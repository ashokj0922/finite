#ifndef WORLD_H
#define WORLD_H

#include <string>
#include <vector>
#include <Eigen>
#include <geom/Mesh.h>

class Obstacle;
class World
{
public:
    static void init(const std::string& filename);
    static void step(double dt);
    static const Mesh& mesh() { return sMesh; }

private:
    World();
    World(const World& other);
    ~World();

    World& operator=(const World& rhs);

    static Mesh sMesh;
    static std::vector<Eigen::Matrix3d> sDeformations;
    static std::vector<Eigen::Matrix3d> sStrains;
    static std::vector<Eigen::Matrix3d> sStresses;

    static std::vector<Obstacle*> sObstacles;
};

#endif // WORLD_H
