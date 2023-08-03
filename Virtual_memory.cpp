#include <iostream>
#include <unordered_map>
#include <vector>

struct Page {
    int pageNumber;
    bool present;
};

class VirtualMemoryManager {
private:
    std::unordered_map<int, Page> pageTable;
    std::vector<int> physicalMemory;

public:
    VirtualMemoryManager(int numPages, int pageSize, int numFrames) {
        for (int i = 0; i < numPages; i++) {
            Page page;
            page.pageNumber = i;
            page.present = false;
            pageTable[i] = page;
        }

        physicalMemory.resize(numFrames, -1);
    }

    void accessMemory(int virtualAddress) {
        int pageNumber = virtualAddress / physicalMemory.size();
        int offset = virtualAddress % physicalMemory.size();

        if (pageTable[pageNumber].present) {
            int frameNumber = pageTable[pageNumber].pageNumber;
            int physicalAddress = frameNumber * physicalMemory.size() + offset;

            std::cout << "Accessing physical address: " << physicalAddress << std::endl;
        } else {
            std::cout << "Page fault occurred. Loading page " << pageNumber << " into physical memory." << std::endl;
            loadPage(pageNumber);
        }
    }

    void loadPage(int pageNumber) {
        for (int i = 0; i < physicalMemory.size(); i++) {
            if (physicalMemory[i] == -1) {
                physicalMemory[i] = pageNumber;
                pageTable[pageNumber].present = true;
                pageTable[pageNumber].pageNumber = i;
                return;
            }
        }

        // Page replacement needed
        std::cout << "Page replacement needed. Selecting page to evict..." << std::endl;

        // In this example, we use a simple FIFO (First-In-First-Out) replacement policy
        int evictedPage = physicalMemory[0];
        physicalMemory[0] = pageNumber;
        pageTable[pageNumber].present = true;
        pageTable[pageNumber].pageNumber = 0;

        std::cout << "Evicted page " << evictedPage << " and loaded page " << pageNumber << " into physical memory." << std::endl;
    }
};

int main() {
    int numPages = 8;
    int pageSize = 1024;  // 1KB
    int numFrames = 4;

    VirtualMemoryManager vmm(numPages, pageSize, numFrames);

    // Access virtual memory addresses
    vmm.accessMemory(2048);   // Page fault, loading page 2 into physical memory
    vmm.accessMemory(3072);   // Page fault, loading page 3 into physical memory
    vmm.accessMemory(1024);   // Page fault, loading page 1 into physical memory
    vmm.accessMemory(2048);   // Page hit, accessing physical address 8192
    vmm.accessMemory(5120);   // Page fault, loading page 5 into physical memory
    vmm.accessMemory(4096);   // Page fault, loading page 4 into physical memory
    vmm.accessMemory(1024);   // Page hit, accessing physical address 4096

    return 0;
}
