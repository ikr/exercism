#include "collatz_conjecture.h"
#include <stdexcept>

namespace collatz_conjecture {
unsigned int steps(int n) {
    if (n <= 0) throw std::domain_error("Positive integer expeced");

    unsigned int answer = 0U;

    while (n != 1) {
        n = (n % 2) ? (3 * n + 1) : (n / 2);
        ++answer;
    }

    return answer;
}
} // namespace collatz_conjecture
