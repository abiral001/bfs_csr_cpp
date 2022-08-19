#include <iostream>
#include "graph.h"
#include "queue.h"

void display(int*, int);

bool inTraversed(int, int*, int);

int main(int args, char **argv)
{
	std::cout<<"Input: ./exe beg csr weight\n";
	if(args!=4){std::cout<<"Wrong input\n"; return -1;}
	
    for (int i = 0; i < args; i++) {
        std::cout << argv[i] << std::endl;
    }
	const char *beg_file=argv[1];
	const char *csr_file=argv[2];
	const char *weight_file=argv[3];

	//template <file_vertex_t, file_index_t, file_weight_t
	//new_vertex_t, new_index_t, new_weight_t>
	graph<long, long, int, long, long, char> *ginst = new graph <long, long, int, long, long, char> (beg_file,csr_file,weight_file);
    //**
    //You can implement your single threaded graph algorithm here.
    //like BFS, SSSP, PageRank and etc.
    for(int i = 0; i < ginst->vert_count; i++) {
        int beg = ginst->beg_pos[i];
        int endpos = ginst->beg_pos[i+1];
        std::cout << i <<"'s neighbor list: " << std::flush;
        for(int j = beg; j < endpos; j++) {
            std::cout<<ginst->csr[j]<<" ";
        }
        std::cout<<"\n";
    }
    // update: 2022/08/18 Adding BFS Block
    
    int totalCost = 0;
    int start = 0;
    int end = ginst->vert_count;
    int *traversed = new int[end];

    std::cout << "Default behaviour is to start from 0 node to highest numbered node" << std::endl;
    // main bfs implementation
    // finding all the path
    int current;
    Queue *q = new Queue();
    int counter = 0;
    q->enqueue(start);
    std::cout << "Current queue size => " << q->getQueueSize() << std::endl;
    while (q->getQueueSize() > 0) {
        do {
            current = q->dequeue();
            if (current == -1) {
                break;
            }
        } while (inTraversed(current, traversed, counter));
        if (current == -1) {
            break;
        }
        traversed[counter++] = current;
        if (current == 5) {
            break;
        }
        for(int i = 0; i < ginst->vert_count; i++) {
            if (i == current) {
                for(int j = ginst->beg_pos[i]; j < ginst->beg_pos[i+1]; j++) {
                    q->enqueue(ginst->csr[j]);
                    std::cout << "Queue => " << std::flush;
                    display(q->getQueue(), q->getQueueSize());
                    std::cout << std::endl;
                }
                break;
            }
        }
        if (current == end) {
            break;
        }
    }
    std::cout << "Traversed path to reach end from start => " << std::flush;
    display(traversed, counter);
    delete [] traversed;
    delete q;
	return 0;	
}

void display(int *path, int length) {
    for (int i=0; i < length; i++) {
        std::cout << path[i] << " " << std::flush;
    }
    std::cout << std::endl;
}

bool inTraversed(int node, int *traversed, int length) {
    for (int i = 0; i < length; i++) {
        std::cout << "check if " << node << " == " << traversed[i] << std::endl;
        if (node == traversed[i]) {
            std::cout << "Already traversed node => " << node << std::endl;
            return true;
        }
    }
    std::cout << "New Node" << std::endl;
    return false;
}
