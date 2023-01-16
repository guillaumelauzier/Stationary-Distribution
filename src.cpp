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
