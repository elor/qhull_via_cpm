#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

#include <libqhullcpp/Qhull.h>

using namespace orgQhull;
using namespace std;

int main() {
  vector<double> points{
      0,   0,   0,  //
      0,   0,   1,  //
      0,   1,   0,  //
      0,   1,   1,  //
      1,   0,   0,  //
      1,   0,   1,  //
      1,   1,   0,  //
      1,   1,   1,  //
      0.5, 0.5, 0.5 //
  };

  // add 100 random points between [0.1, 0.9]
  for (int i = 0; i < 100; i++) {
    points.push_back(rand() / RAND_MAX);
    points.push_back(rand() / RAND_MAX);
    points.push_back(rand() / RAND_MAX);
  }

  // Qhull qhull("comment", 3, points.size() / 3, points.data(), "d Qz Qx Qc");
  Qhull qhull("comment", 3, points.size() / 3, points.data(), "Qx Qc");

  cout << "Qhull run complete" << endl;

  // number of vertices in convex hull
  cout << "Number of vertices in convex hull: " << qhull.vertexCount() << endl;

  // Print vertices of the convex hull
  for (auto vertex : qhull.vertexList()) {
    cout << vertex.point().toStdVector()[0] << " "
         << vertex.point().toStdVector()[1] << " "
         << vertex.point().toStdVector()[2] << endl;
  }

  cout << "Done" << endl;
  return EXIT_SUCCESS;
}
