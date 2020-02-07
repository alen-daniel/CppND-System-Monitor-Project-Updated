#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
public:
  float Utilization();  // TODO: See src/processor.cpp

  // TODO: Declare any necessary private members
private:
    float previous_cpu_usage_active_{0.0}, previous_cpu_usage_idle_{0.0};
};

#endif