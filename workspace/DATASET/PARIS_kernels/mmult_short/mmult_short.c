//*****************************************************************************
//
// AUTHOR:  Sergio Cuenca based on Heather Quinn mm_test.c
// CONTACT INFO:
// LAST EDITED: 08/03/2021
//
//*****************************************************************************

#define side 4

const int first_matrix[side][side] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {8, 7, 6, 5}, {4, 3, 2, 1}};
const int second_matrix[side][side] = {{8, 7, 6, 5}, {4, 3, 2, 1}, {1, 2, 3, 4}, {5, 6, 7, 8}};
const int check_matrix[side][side] = {{39, 43, 47, 51}, {111, 115, 119, 123}, {123, 119, 115, 111}, {51, 47, 43, 39}};
int result_matrix[side][side];
unsigned int total_errors;

void init()
{
    total_errors = 0;
    for (int i = 0; i < side; i++)
    {
        for (int j = 0; j < side; j++)
        {
            result_matrix[i][j] = 0;
        }
    }
}

void test()
{
    int sum = 0;
    // MM
    for (int i = 0; i < side; i++)
    {
        for (int j = 0; j < side; j++)
        {
            for (int k = 0; k < side; k++)
            {
                sum = sum + first_matrix[i][k] * second_matrix[k][j];
            }

            result_matrix[i][j] = sum;
            sum = 0;
        }
    }
}

void runMain()
{
    init();
    test();
}

int main()
{
    runMain();
    return 0;
}