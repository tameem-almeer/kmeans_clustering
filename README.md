# K-means Clustering in C++

This is a basic implementation of the K-means clustering algorithm in C++. It performs clustering on a set of 2D data points and outputs the resulting centroids and cluster assignments.

## Overview

The program implements the K-means clustering algorithm, which is a popular unsupervised machine learning algorithm. The algorithm works by partitioning a set of points into `k` clusters. Each cluster is represented by a centroid (mean of the points in the cluster). The program runs iteratively to update centroids and reassign points to the nearest centroid until convergence or a set number of iterations.

## Features

- K-means clustering with user-specified `k` clusters.
- Random initialization of centroids.
- Euclidean distance calculation for cluster assignment.
- Output of final centroids and the cluster each data point belongs to.

## Requirements

- C++ compiler (e.g., `g++`, `clang++`).

## Compilation and Running

1. **Clone the repository:**

   First, clone this repository to your local machine using the following command:

   ```bash
   git clone https://github.com/yourusername/kmeans_clustering.git
