#include "processor.h"
#include <thread>
#include "linux_parser.h"
#include <unistd.h>

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() 
{
    float current_cpu_usage_active = static_cast<float>(LinuxParser::ActiveJiffies());
    float current_cpu_usage_idle = static_cast<float>(LinuxParser::IdleJiffies());
    float cpu_usage_active_delta = current_cpu_usage_active - previous_cpu_usage_active_; 
    float cpu_usage_idle_delta = current_cpu_usage_idle - previous_cpu_usage_idle_; 
    previous_cpu_usage_active_ = current_cpu_usage_active;
    previous_cpu_usage_idle_ = current_cpu_usage_idle;
    
    return cpu_usage_active_delta/(cpu_usage_idle_delta + cpu_usage_active_delta); 
}