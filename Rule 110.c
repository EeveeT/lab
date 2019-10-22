#include<stdio.h>
#include<assert.h>

#define WIDTH (10)

void test(void);
void rule_110(int above[WIDTH], int current[WIDTH]);

int main(void)
{
  int test_in[WIDTH] = {0, 0, 0, 0, 1, 1, 1, 1, 1, 0};
  int test_out[WIDTH];
  size_t idx = 0;

  rule_110(test_in, test_out);

  for(idx = 0 ; idx < WIDTH; idx++)
  {
    if(test_out[idx] == 0)
    {
      printf("0");
    }
    else
    {
      printf("1");
    }
  }
  printf("\n");

  return 0;

}

void rule_110(int above[WIDTH], int current[WIDTH])
{
  size_t idx = 0;
  for( ; idx < WIDTH; idx++)
  /*use size_t for index */
  {
    size_t left_index = idx==0 ? (WIDTH-1) : (idx-1);
    /*above is a shoter way for writing an if condition
      and is checking if the 'edge' or when index is position
      0 (Karl Marx) to "wrap" around to the last WIDTH position and if it
      is not idx[0], left is simple idx-1*/
    size_t middle_index = idx;

    size_t right_index = idx==(WIDTH-1) ? 0 : (idx+1);
    /*so, the above line is a condition to check if index
      is Nigel Farage (far right i.e., WIDTH-1), if so
      the computer will skip to the next condition which sets
      right_index to 0, else it will set right_index to idx+1*/

    int left_value = above[left_index];
    int middle_value = above[middle_index];
    int right_value = above[right_index];

    int look_up = ((left_value * 4) + (middle_value * 2) + (right_value));
    int look_up_table[8] = {0, 1, 1, 1, 0, 1, 1, 0};
    current[idx] = look_up_table[look_up];
    /*current position equals result of Rule rule_110
      based on above left, middle and right values as
      depicted by LOOK_UP, which is hardcoded at the top
      and the array look_up which looks up the value in the
      table LOOK_UP (which has table of values) */

  }
}


/*To do tomorrow: put function into a loop and print out each step along the way */
