#include <iostream>
#include <cstdlib>
#include <random>
#include <chrono>

template <uint64_t N>
class Matrix
{
    private:
        double* array;

        static double random_number()
        {
            static std::mt19937 generator{std::random_device()()};
            return std::uniform_real_distribution<double>(0.5, 2.0)(generator);
        }
    
    public:
        Matrix() : array(new double[N * N])
        {
            for (uint64_t i = 0; i < N; i++)
                for (uint64_t j = 0; j < N; j++)
                    array[i * N + j] = random_number();
        }

        ~Matrix() { delete[] array; }
        
        Matrix& square()
        {
            auto result = new double[N * N];

            for (uint64_t i = 0; i < N; i++)
                for (uint64_t j = 0; j < N; j++)
                {
                    result[i * N + j] = 0.0;
                    for (uint64_t k = 0; k < N; k++)
                        result[i * N + j] += array[i * N + k] * array[k * N + j];
                }

            delete[] array;
            array = result;
            return *this;
        }
};

template <uint64_t N>
void measure(Matrix<N>& matrix, uint32_t iterations)
{
    using namespace std::chrono;
    auto startTime = high_resolution_clock::now();

    for (uint32_t i = 0; i < iterations; i++)
        matrix.square();

    auto endTime = high_resolution_clock::now();
    auto time = duration_cast<duration<double>>( (endTime - startTime) / iterations );

    std::cout << N << "x" << N << " process took " << time.count() << " seconds." << std::endl;
}

int main()
{
    Matrix<10>    matrix_10;
    Matrix<100>   matrix_100;
    Matrix<1000>  matrix_1000;
    //Matrix<10000> matrix10000;

    measure(matrix_10, 1000);
    measure(matrix_100, 100);
    measure(matrix_1000, 10);

    return 0;
}