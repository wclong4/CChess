// Elapsed Real Time for input-4.txt: 0m1.864s

#include <stdio.h>
#include <stdbool.h>
#include <cuda_runtime.h>

// Input sequence of integers.
int *vList;

// Number of integers on the list.
int vCount = 0;

// Capacity of the list of integers.
int vCap = 0;

// Target sum.
int target_sum;

// General function to report a failure and exit.
static void fail( char const *message ) {
  fprintf( stderr, "%s\n", message );
  exit( 1 );
}

// Print out a usage message, then exit.
static void usage() {
  printf( "usage: sequence <target_sum> [report]\n" );
  exit( 1 );
}

// Read the list of values.
__host__ void readList() {
  // Set up initial list and capacity.
  vCap = 5;
  vList = (int *) malloc( vCap * sizeof( int ) );

  // Keep reading as many values as we can.
  int v;
  while ( scanf( "%d\n", &v ) == 1 ) {
    // Grow the list if needed.
    if ( vCount >= vCap ) {
      vCap *= 2;
      vList = (int *) realloc( vList, vCap * sizeof( int ) );
    }

    // Store the latest value in the next array slot.
    vList[ vCount++ ] = v;
  }
}

__global__ void checkSum( int *devList, int *localCounts, int vCount, bool report, int target_sum) {
  int idx = blockDim.x * blockIdx.x + threadIdx.x;
  // citation, this is heavily modified from my previous homeworks (I looked at HW 3 and 4) for this exact problem
  // the approach is similar, but I changed it to be as close as possible to the example output
  // this is the bulk of the code I wrote, so ~ 1/2, but I am pretty sure that is okay.

  // make sure our index is below vCount
  // don't want to go out of bounds
  if ( idx < vCount ) {
    // start our sum at 0
    int sum = 0;
    // start at the end of our section and go backwards checking if we have found our sum
    // something like this if idx = 4 and vCount is 4, we add up the x's values
    // . . . . .
    // . . . . x 
    // . . . x x
    // . . x x x
    // and so on and so forth
    for (int j = idx; j >= 0; j--) {
      // add our x to sum
      sum += devList[j];
      // if sum is target, then increment localCounts
      if (sum == target_sum) {
        localCounts[idx]++; 
        // report if needed
        if (report) { 
          printf("I’m thread %d. Local count: %d Sequence found at: %d-%d.\n", idx, localCounts[idx], j, idx);
        }
      }
    }
    // if localCounts of idx is 0 and we are reporting, then print out special statement
    if (localCounts[idx] == 0 && report) {
      printf("I’m thread %d. Local count: %d\n", idx, 0);
    }
  }
  // end citation
}

int main( int argc, char *argv[] ) {
  if ( argc < 2 || argc > 3 )
    usage();

  if ( sscanf( argv[ 1 ], "%d", &target_sum ) != 1)
    usage();

  bool report = false;
  if ( argc == 3 ) {
    if ( strcmp( argv[ 2 ], "report" ) != 0 )
      usage();
    report = true;
  }
  // should now have vList and vCount
  readList();

  // Add code to allocate memory on the device and copy over the list.
  // citation, got from randomList.cu on moodle. I don't really know if I need to cite this
  // because it is just basic syntax, like if I did printf would I have to cite that?
  int *devList = NULL;
  if ( cudaMalloc((void **)&devList, vCount * sizeof(int) ) != cudaSuccess )
    fail( "Failed to allocate space for length list on device" );
  // Add code to copy the list over to the device.
  if ( cudaMemcpy( devList, vList, vCount * sizeof(int),
                   cudaMemcpyHostToDevice) != cudaSuccess )
    fail( "Failed to copy list to device" );
  // end citation
  // Add code to allocate space on the device to hold the results.
  int *localCounts = NULL;
  if ( cudaMalloc((void **)&localCounts, vCount * sizeof(int) ) != cudaSuccess )
    fail( "Failed to allocate space for lenght list on device" );
  // Block and grid dimensions.
  int threadsPerBlock = 1024;
  // Round up for the number of blocks we need.
  int blocksPerGrid = ( vCount + threadsPerBlock - 1 ) / threadsPerBlock;
  printf("Blocks per grid %d\n", blocksPerGrid);
  // Run our kernel on these block/grid dimensions (you'll need to add some parameters)
  checkSum<<<blocksPerGrid, threadsPerBlock>>>( devList, localCounts, vCount, report, target_sum );
  cudaError_t error;
  if ( (error = cudaGetLastError()) != cudaSuccess ) {
    printf("%s\n", cudaGetErrorString(error));
    fail( "Failure in CUDA kernel execution." );
  }
  // Add code to copy results back to the host, compare the local maximum lengths
  // and report the final maximum length

  // allocate memory for the counts here
  int * allCounts = (int *) malloc(vCount * sizeof(int));
  // set all counts to 0
  memset(allCounts, 0, vCount * sizeof(int));

  // citation got from randomList.cu from moodle
  if ( cudaMemcpy( allCounts, localCounts, vCount * sizeof(int),
                   cudaMemcpyDeviceToHost) != cudaSuccess )
    fail( "Can't copy list from device to host" );
  // end citation

  int sum = 0;
  for (int i = 0; i < vCount; i++) {
    sum += allCounts[i];
  }
  printf("Total count: %d\n", sum);
  // Free memory on the device and the host.
  // ...
  free( vList );
  free(allCounts);
  cudaFree( localCounts );
  cudaFree( devList );
  cudaDeviceReset();

  return 0;
}
