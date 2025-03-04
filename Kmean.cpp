#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Point {
    double x, y;
};

double euclidean_distance(const Point &p1, const Point &p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

void kmeans(vector<Point> &data, int k, int max_iterations) {
    srand(time(0));
    vector<Point> centroids(k);
    for (int i = 0; i < k; ++i) {
        centroids[i] = data[rand() % data.size()];
    }

    vector<int> labels(data.size(), -1);
    vector<vector<Point>> clusters(k);

    for (int iter = 0; iter < max_iterations; ++iter) {
        for (int i = 0; i < k; ++i) {
            clusters[i].clear();
        }

        for (size_t i = 0; i < data.size(); ++i) {
            double min_dist = euclidean_distance(data[i], centroids[0]);
            int label = 0;
            for (int j = 1; j < k; ++j) {
                double dist = euclidean_distance(data[i], centroids[j]);
                if (dist < min_dist) {
                    min_dist = dist;
                    label = j;
                }
            }
            labels[i] = label;
            clusters[label].push_back(data[i]);
        }

        bool converged = true;
        for (int i = 0; i < k; ++i) {
            double mean_x = 0, mean_y = 0;
            for (const auto &p : clusters[i]) {
                mean_x += p.x;
                mean_y += p.y;
            }
            mean_x /= clusters[i].size();
            mean_y /= clusters[i].size();

            if (euclidean_distance(centroids[i], {mean_x, mean_y}) > 1e-4) {
                converged = false;
                centroids[i] = {mean_x, mean_y};
            }
        }

        if (converged) {
            break;
        }
    }

    for (int i = 0; i < k; ++i) {
        cout << "Centroid " << i + 1 << ": (" << centroids[i].x << ", " << centroids[i].y << ")" << endl;
    }

    cout << "\nCluster assignments:" << endl;
    for (size_t i = 0; i < data.size(); ++i) {
        cout << "Point (" << data[i].x << ", " << data[i].y << ") is in cluster " << labels[i] + 1 << endl;
    }
}

int main() {
    vector<Point> data = {{2.0, 3.0}, {3.0, 3.5}, {4.0, 4.0}, {8.0, 8.5}, {9.0, 9.5}, {10.0, 10.0}};
    int k = 2;
    int max_iterations = 100;
    kmeans(data, k, max_iterations);
    return 0;
}
