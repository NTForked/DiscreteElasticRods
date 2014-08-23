#ifndef SPIRAL_H
#define SPIRAL_H

#include "RenderObject.h"
#include "ElasticRod.h"

class Spiral
{
public:
    Spiral();
    ~Spiral();

    void init(const RenderObject* object);
    void update(mg::Real dt);

public:
    mg::Real m_radius;
    mg::Real m_lenght;

    mg::Real m_bendStiffness;
    mg::Real m_twistStiffness;
    mg::Real m_maxForce;

    unsigned m_nParticles;
    unsigned m_nIterations;

    std::vector<ElasticRod*> m_strands;

private:
    RodParams* m_rodParams;
    const RenderObject* m_object;

private:
    void updateRod(ElasticRod& rod, mg::Real dt) const;
    void accumulateExternalForces(const ElasticRod& rod, std::vector<mg::Vec3D>& o_forces) const;
};

#endif // SPIRAL_H
