# Stationary-Distribution

The stationary distribution of a Markov chain is the long-term probability distribution of the states, assuming the chain has reached a steady state. The stationary distribution is given by the solution of the following equation:

π * P = π

Where π is the stationary distribution vector and P is the transition matrix of the Markov chain.

In C++, the stationary distribution can be calculated by solving the linear equations represented by the above equation. One way to do this is by using a numerical method, such as the Jacobi method, Gauss-Seidel method, or the Power method.

Here's an example of how to calculate the stationary distribution using the Jacobi method in C++:

```
#include <iostream>
#include <cmath>
using namespace std;

const int N = 3; // Number of states
const int T = 20; // Number of time steps
const double eps = 1e-6; // Accuracy threshold

double transitionMatrix[N][N] = {
    {0.7, 0.2, 0.1},
    {0.1, 0.6, 0.3},
    {0.2, 0.3, 0.5}
};

int main() {
    double pi[N];
    double pi_new[N];
    // Initialize pi with a random distribution
    for (int i = 0; i < N; i++) {
        pi[i] = (double)rand() / RAND_MAX;
    }
    // Normalize pi
    double sum = 0;
    for (int i = 0; i < N; i++) {
        sum += pi[i];
    }
    for (int i = 0; i < N; i++) {
        pi[i] /= sum;
    }
    // Iterate until convergence
    for (int t = 0; t < T; t++) {
        // Update pi_new
        for (int i = 0; i < N; i++) {
            pi_new[i] = 0;
            for (int j = 0; j < N; j++) {
                pi_new[i] += pi[j] * transitionMatrix[j][i];
            }
        }
        // Check for convergence
        double error = 0;
        for (int i = 0; i < N; i++) {
            error += abs(pi[i] - pi_new[i]);
        }
        if (error < eps) {
            break;
        }
        // Update pi
        for (int i = 0; i < N; i++) {
            pi[i] = pi_new[i];
        }
    }
    // Print the stationary distribution
    cout << "Stationary distribution:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "State " << i << ": " << pi[i] << endl;
    }
    return 0;
}

```

This code defines a transition matrix with 3 states and uses the Jacobi method to calculate the stationary distribution of the Markov chain. The method uses an initial guess of the stationary distribution vector, and iterates over the equation until the error is smaller than a certain threshold. The result is stored in the pi array and the final result is printed out in the end.
