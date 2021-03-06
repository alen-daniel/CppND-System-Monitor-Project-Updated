#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

// TODO: Return this process's ID
int Process::Pid() const {
    return pid_; 
}

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() const { 
    return cpu_active_;
}

void Process::UpdateCpuUtilization()
{
    float current_cpu_usage_active = static_cast<float>(LinuxParser::ActiveJiffies(Pid()));
    float current_cpu_usage_idle = static_cast<float>(LinuxParser::IdleJiffies());
    float cpu_usage_active_delta = current_cpu_usage_active - previous_cpu_usage_active_; 
    float cpu_usage_idle_delta = current_cpu_usage_idle - previous_cpu_usage_idle_; 
    previous_cpu_usage_active_ = current_cpu_usage_active;
    previous_cpu_usage_idle_ = current_cpu_usage_idle;
    cpu_active_ = (cpu_usage_active_delta)/(cpu_usage_idle_delta + cpu_usage_active_delta); 
}

// TODO: Return the command that generated this process
string Process::Command() { 
    return LinuxParser::Command(Pid()); 
}

// TODO: Return this process's memory utilization
string Process::Ram() { 
    return LinuxParser::Ram(Pid()); 
}

// TODO: Return the user (name) that generated this process
string Process::User() { 
    return LinuxParser::User(Pid()); 
}

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { 
    return LinuxParser::UpTime(Pid()); 
}

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const {   
    return CpuUtilization() < a.CpuUtilization();
}

bool Process::operator>(Process const& a) const {   
    return CpuUtilization() > a.CpuUtilization();
}