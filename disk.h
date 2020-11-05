//
// Created by Chris on 10/27/2020.
//

#ifndef __DISK_H__
#define __DISK_H__
#include <vector>
#include <iostream>

using namespace std;

template <class T>
class Disk {
private:
    vector<T> diskblocks;
    vector<int> freeBlocks;
    int readCount, writeCount;
protected:
public:
    Disk<T>() {
        readCount = 0;
        writeCount = 0;
    }
    ~Disk() {
        cerr << "Number of Blocks Read : " << readCount << endl;
        cerr << "Number of Blocks Written: " << writeCount << endl;
    }

    int getNumberOfBlocksRead() {
        return readCount;
    }

    int getNumberOfBlocksWritten() {
        return writeCount;
    }

    void writeBlock(int i, T block) {
        if (i < 0 || i >= diskblocks.size()) {
            cerr << "Invalid address in writeBlock -- Address = " << i << endl;
            cerr << "Block not written." << endl;
            return;
        }
        diskblocks[i] = block;
        writeCount++;
    }

    T readBlock(int i) {
        if (i < 0 || i >= diskblocks.size()) {
            cerr << "Invalid address in readBlock -- Address = " << i << endl;
            cerr << "Block not written." << endl;
            return *(new T());
        }
        readCount++;
        return diskblocks[i];
    }

    int createBlock() {
        if (freeBlocks.size() == 0) {
            diskblocks.push_back(* new T());
            return diskblocks.size()-1;
        }
        else {
            int location = freeBlocks[freeBlocks.size() - 1];
            freeBlocks.pop_back();
            return location;
        }
    }

    void returnBlock(int i) {
        if (i < 0 || i >diskblocks.size()) {
            cerr << "Invalid address in returnBlock -- Address = " << i << endl;
            cerr << "Block not added to freeBlocks" << endl;
        }
        else {
            freeBlocks.push_back(i);
        }
    }
};

#endif