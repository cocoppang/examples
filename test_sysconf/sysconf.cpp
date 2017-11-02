#include <stdio.h>
#include <unistd.h>
#include <iostream>
using namespace std;
int main()
{
    long ncpus = sysconf(_SC_NPROCESSORS_CONF);
    long cur_cpus = sysconf(_SC_NPROCESSORS_ONLN);
    long phy_pages = sysconf(_SC_PHYS_PAGES);
    long avail_phy_pages = sysconf(_SC_AVPHYS_PAGES);

    cout << "Number of CPUS: "<< ncpus << endl;
    cout << "Current Onlined Number of CPUS: " << cur_cpus << endl;
    cout << "Number of PAGES: " << phy_pages << endl;
    cout << "Current Available Number of PAGES: " << avail_phy_pages << endl;

    return 0;
}
