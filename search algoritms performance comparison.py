#!/usr/bin/env python
# coding: utf-8

# # <center>HACETTEPE UNIVERSITY
# # <center>DEPARTMENT OF COMPUTER ENGINEERING
# # <center>BBM405
# # <center>HOMEWORK #1
# 
# 
# **Subject: Applying Search Algorithms on Search Problems<br>
# Deadline: 10.5.2020<br>
# Programming Language: Python<br>
# Student ID: 21727432<br>
# Student Name: Ali Kayadibi**<br>
# 
# 
# # INTRODUCTION / AIM 
# 
# In this homework, we are expected to implement four search algorithms such as:
# * Depth First search 
# * Breadth First Search
# * Uniform Cost Search 
# * A* search. <br>
# 
# Depth First Search is an algorithm for traversing or searching tree or graph data structures. The algorithm starts at the root node (selecting some arbitrary node as the root node in the case of a graph) and explores as far as possible along each branch before backtracking.
# 
# Breadth-first search (BFS) is an algorithm for traversing or searching tree or graph data structures. It starts at the tree root (or some arbitrary node of a graph, sometimes referred to as a 'search key'), and explores all of the neighbor nodes at the present depth prior to moving on to the nodes at the next depth level.
# 
# Uniform cost search is a tree search algorithm related to breadth-first search.Uniform cost search determines a path to the goal state that has the lowest weight.
# 
# A* is a graph traversal and path search algorithm, which is often used in computer science due to its completeness, optimality, and optimal efficiency.One major practical drawback is its O(b^d) space complexity, as it stores all generated nodes in memory.
# 
# After implementing our algorithms, we are expected to find creative search problems suitable to apply our search algorithm.After applying our algorithms, we are expected to compare our results we obtained from these four algorithms based on four criteria.They are:
# 
# * Optimality
# * Completeness
# * Time 
# * Space Complexity.
# 
# In this homework we are expected to find two different search problems one small one larger scale.I will call them Problem 1 and Problem 2.
# 
# 
# 

# # Implementation of Search Algorithms
# 
# Below blocks defines our seach algorithm's graph classes, their functions. I have uptaded them for my problems and added a print path part to output better.These parts are taken from https://github.com/chitholian/AI-Search-Algorithms.

# ***A Star Graph***

# In[2]:


import math
import random
from queue import heappop, heappush
from math import inf
import time
import test
from collections import deque
import sys

class AStar_Graph:
    def __init__(self, directed=True):
        self.edges = {}
        self.huristics = {}
        self.directed = directed

    def add_edge(self, node1, node2, cost = 1, __reversed=False):
        try: neighbors = self.edges[node1]
        except KeyError: neighbors = {}
        neighbors[node2] = cost
        self.edges[node1] = neighbors
        if not self.directed and not __reversed: self.add_edge(node2, node1, cost, True)

    def set_huristics(self, huristics={}):
        self.huristics = huristics

    def neighbors(self, node):
        try: return self.edges[node]
        except KeyError: return []

    def cost(self, node1, node2):
        try: return self.edges[node1][node2]
        except: return inf


    def a_star_search(self, start, goal,output):
        found, fringe, visited, came_from, cost_so_far = False, [(self.huristics[start], start)], set([start]), {start: None}, {start: 0}
        output.write('{:11s} | {}\n'.format('Expand Node', 'Fringe'))
        output.write('--------------------\n')
        output.write('{:11s} | {}\n'.format('-', str(fringe[0])))
        while not found and len(fringe):
            _, current = heappop(fringe)
            output.write('{:11s} | '.format(current))
            if current == goal: found = True; break
            for node in self.neighbors(current):
                new_cost = cost_so_far[current] + self.cost(current, node)
                if node not in visited or cost_so_far[node] > new_cost:
                    visited.add(node); came_from[node] = current; cost_so_far[node] = new_cost
                    heappush(fringe, (new_cost + self.huristics[node], node))
            output.write(', '.join([str(n) for n in fringe])+"\n")
        if found: output.write("\n"); return came_from, cost_so_far[goal]
        else: output.write('No path from {} to {}\n'.format(start, goal)); return None, inf

    @staticmethod
    def print_path(came_from, goal,output):
        parent = came_from[goal]
        if parent:
            AStar_Graph.print_path(came_from, parent,output)
        else: output.write(goal);return
        output.write(' =>'+goal)


    def __str__(self):
        return str(self.edges)


# ***Breadth First Search Graph***

# In[4]:


class BFSGraph:
    def __init__(self, directed=True):
        self.edges = {}
        self.directed = directed

    def add_edge(self, node1, node2, __reversed=False):
        try: neighbors = self.edges[node1]
        except KeyError: neighbors = set()
        neighbors.add(node2)
        self.edges[node1] = neighbors
        if not self.directed and not __reversed: self.add_edge(node2, node1, True)

    def neighbors(self, node):
        try: return self.edges[node]
        except KeyError: return []

    def breadth_first_search(self, start, goal,output):
        found, fringe, visited, came_from = False, deque([start]), set([start]), {start: None}
        output.write('{:11s} | {}\n'.format('Expand Node', 'Fringe'))
        output.write('--------------------\n')
        output.write('{:11s} | {}\n'.format('-', start))
        while not found and len(fringe):
            current = fringe.pop()
            output.write('{:11s} | '.format(current))
            if current == goal: found = True; break
            for node in self.neighbors(current):
                if node not in visited: visited.add(node); fringe.appendleft(node); came_from[node] = current
            output.write(', '.join(fringe)+"\n")
        if found: output.write("\n"); return came_from
        else: output.write('No path from {} to {}'.format(start, goal))

    @staticmethod
    def print_path(came_from, goal,output):
        parent = came_from[goal]
        if parent:
            BFSGraph.print_path(came_from, parent,output)
        else: output.write(goal);return
        output.write(' =>'+ goal)


    def __str__(self):
        return str(self.edges)


# ***Depth First Search Graph***

# In[5]:


class DFSGraph:
    def __init__(self, directed=True):
        self.edges = {}
        self.directed = directed

    def add_edge(self, node1, node2, __reversed=False):
        try: neighbors = self.edges[node1]
        except KeyError: neighbors = set()
        neighbors.add(node2)
        self.edges[node1] = neighbors
        if not self.directed and not __reversed: self.add_edge(node2, node1, True)

    def neighbors(self, node):
        try: return self.edges[node]
        except KeyError: return []

    def depth_first_search(self, start, goal,output):
        found, fringe, visited, came_from = False, deque([start]), set([start]), {start: None}
        output.write('{:11s} | {}\n'.format('Expand Node', 'Fringe'))
        output.write('--------------------\n')
        output.write('{:11s} | {}\n'.format('-', start))
        while not found and len(fringe):
            current = fringe.pop()
            output.write('{:11s} | '.format(current))
            if current == goal: found = True; break
            for node in self.neighbors(current):
                if node not in visited: visited.add(node); fringe.append(node); came_from[node] = current
            output.write(', '.join(fringe)+"\n")
        if found: output.write("\n"); return came_from
        else: output.write('No path from {} to {}\n'.format(start, goal))

    @staticmethod
    def print_path(came_from, goal,output):
        parent = came_from[goal]
        if parent:
            DFSGraph.print_path(came_from, parent,output)
        else: output.write(goal);return
        output.write(' =>'+goal)


    def __str__(self):
        return str(self.edges)


# ***Uniform Cost Seach Graph***

# In[6]:


class UCSGraph:
    def __init__(self, directed=True):
        self.edges = {}
        self.directed = directed

    def add_edge(self, node1, node2, cost = 1, __reversed=False):
        try: neighbors = self.edges[node1]
        except KeyError: neighbors = {}
        neighbors[node2] = cost
        self.edges[node1] = neighbors
        if not self.directed and not __reversed: self.add_edge(node2, node1, cost, True)

    def neighbors(self, node):
        try: return self.edges[node]
        except KeyError: return []

    def cost(self, node1, node2):
        try: return self.edges[node1][node2]
        except: return inf


    def uniform_cost_search(self, start, goal,output):
        found, fringe, visited, came_from, cost_so_far = False, [(0, start)], set([start]), {start: None}, {start: 0}
        output.write('{:11s} | {}\n'.format('Expand Node', 'Fringe'))
        output.write('--------------------\n')
        output.write('{:11s} | {}\n'.format('-', str((0, start))))
        while not found and len(fringe):
            _, current = heappop(fringe)
            output.write('{:11s} | '.format(current))
            if current == goal: found = True; break
            for node in self.neighbors(current):
                new_cost = cost_so_far[current] + self.cost(current, node)
                if node not in visited or cost_so_far[node] > new_cost:
                    visited.add(node); came_from[node] = current; cost_so_far[node] = new_cost
                    heappush(fringe, (new_cost, node))
            output.write(', '.join([str(n) for n in fringe])+"\n")
        if found: output.write("\n"); return came_from, cost_so_far[goal]
        else: output.write('No path from {} to {}'.format(start, goal)); return None, inf

    @staticmethod
    def print_path(came_from, goal,output):
        parent = came_from[goal]
        if parent:
            UCSGraph.print_path(came_from, parent,output)
        else: output.write(goal);return
        output.write(' =>'+ goal)


    def __str__(self):
        return str(self.edges)


# 
# 
# ### <center> Problem 1
#     
#     
# For Problem 1 i have selected a path finding problem. My scenario is, i have maze a mice and a cheese is randomly dropped on random coordinates on randomly generated map where i represent 1's with can't go through(walls, objects etc..) and 0's with can go through.Mice's aim is to find the cheese using these four algorithms.
# <br>
# <img style="float: left;" src="map1.png"> 
# <br><br><br><br><br><br><br><br>
# This is my map. It is randomly generated , every coordinate is represented as nodes, we have one starting node(randomly generated) this represent where the mouse is dropped and a finish node(randomly generated) this represent where the cheese is.Mouse's aim is to find and eat the cheese.
# <br><br><br>
# For creating a map , I create a square map with given size, for this experiment i will be using 100, 200, 300 and 400 to compare my algorithms.
# <br><br><br><br><br><br><br><br><br> 

# # Creating Square Map for Problem 1
# 
# Below block creates a square map with given size.It puts random ones and zeros inside this map.Ones represent can't go through and zeros represent can go through.We will be using this in search algorithms and this will change algorithm's performance.

# In[3]:


def create_file2(filename,row_range):
    file = open(filename,"w")
    list = []
    for i in range(row_range):
        row = ""
        for j in range(row_range):
            value = random.randint(0,1)

            row += str(value)
        list.append(row)
        file.write(row+"\n")

    random_list = []
    for i in range(2):
        while (True):
            x = random.randint(0, row_range-1 )
            y = random.randint(0, row_range-1 )
            value = list[x][y]
            if (int(value) != 1):
                random_list.append(str(x)+","+str(y))
                break
    file.close()
    return random_list[0],random_list[1]


# #  Functions for Running Search Algorithms On Map For Problem 1
# 
# Below code blocks runs the four algorithm, keeps time and outputs output of operations and times.
# 
# In a* search algorithm, heuristic values are bird flight distance values.
# In uniform cost search, the distance between the nodes are costs to reach from that node to that node.

# In[7]:


def data_astar_nodes(file_name,start,goal,output_name):

    graph = AStar_Graph(directed=True)
    start_time = None
    try:
        output = open(output_name, "w")
        file = open(file_name,"r")
        file_rows = file.readlines()
        heuristic_dict = {}
        for row in range(len(file_rows)): # row = 0,1,2,3,4,5
            file_rows[row] = file_rows[row].strip("\n")
            for column in range(len(file_rows[row])): # column 0,1,2,3,4........

                if (int(file_rows[row][column]) != 1):
                    goal_row = int(goal.split(",")[0])
                    goal_column = int(goal.split(",")[1])
                    heuristic_dict[str(row)+","+str(column)] = float("{:.2f}".format(math.sqrt(math.pow(row-goal_row,2)+math.pow(column-goal_column,2))))
                        #round(math.sqrt(math.pow(row-goal_row,2)+math.pow(column-goal_column,2)),2)

                    for row_temp in range(row-1,row+2):
                        for column_temp in range(column-1,column+2):
                            try:
                                if(row_temp == -1 or column_temp == -1 or (row == row_temp and column == column_temp)):
                                    raise KeyError
                                if(  int(file_rows[row_temp][column_temp]) != 1):
                                    graph.add_edge(str(row)+","+str(column),str(row_temp)+","+str(column_temp),
                                                   #round(math.sqrt(math.pow(row-row_temp,2)+math.pow(column-column_temp,2)),2))
                                                   float("{:.2f}".format(math.sqrt(math.pow(row-row_temp,2)+math.pow(column-column_temp,2)))))
                            except:
                                pass

        graph.set_huristics(heuristic_dict)
        start_time = time.time()
        traced_path, cost = graph.a_star_search(start, goal,output)
        if (traced_path): output.write('Path: '); AStar_Graph.print_path(traced_path, goal,output); output.write('\nCost:'+str(cost)+"\n")
        return time.time() - start_time
    except KeyError:
        print("Start Location not found")


# In[8]:


def data_bfs_nodes(file_name,start,goal,output_name):

    graph = BFSGraph(directed=True)
    try:
        output = open(output_name, "w")
        file = open(file_name,"r")
        file_rows = file.readlines()

        for row in range(len(file_rows)): # row = 0,1,2,3,4,5
            file_rows[row] = file_rows[row].strip("\n")
            for column in range(len(file_rows[row])): # column 0,1,2,3,4........
                if (int(file_rows[row][column]) != 1):
                    for row_temp in range(row-1,row+2):
                        for column_temp in range(column-1,column+2):
                            try:
                                if(row_temp == -1 or column_temp == -1 or (row == row_temp and column == column_temp)):
                                    raise KeyError
                                if(  int(file_rows[row_temp][column_temp]) != 1):
                                    graph.add_edge(str(row)+","+str(column),str(row_temp)+","+str(column_temp))
                            except:
                                pass
        start_time = time.time()
        traced_path = graph.breadth_first_search(start, goal,output)
        if (traced_path): output.write('Path: '); BFSGraph.print_path(traced_path, goal,output);output.write("\n")
        return time.time() - start_time
    except KeyError:
        return time.time() - start_time


# In[9]:


def data_dfs_nodes(file_name,start,goal,output_name):

    graph = DFSGraph(directed=False)
    try:
        output = open(output_name, "w")
        file = open(file_name,"r")
        file_rows = file.readlines()

        for row in range(len(file_rows)): # row = 0,1,2,3,4,5
            file_rows[row] = file_rows[row].strip("\n")
            for column in range(len(file_rows[row])): # column 0,1,2,3,4........
                if(int(file_rows[row][column]) != 1):
                    for row_temp in range(row-1,row+2):
                        for column_temp in range(column-1,column+2):
                            try:
                                if(row_temp == -1 or column_temp == -1 or (row == row_temp and column == column_temp)):
                                    raise KeyError
                                if(  int(file_rows[row_temp][column_temp]) != 1):

                                    graph.add_edge(str(row)+","+str(column),str(row_temp)+","+str(column_temp))

                            except:
                                pass

        start_time = time.time()
        traced_path = graph.depth_first_search(start, goal,output)
        if (traced_path): output.write('Path: '); DFSGraph.print_path(traced_path, goal,output);output.write("\n")
        return time.time() - start_time
    except KeyError:
        print("Start Location not found")
        return time.time() - start_time


# In[10]:


def data_ucs_nodes(file_name,start,goal,output_name):

    graph = UCSGraph(directed=True)
    try:
        output = open(output_name,"w")
        file = open(file_name,"r")
        file_rows = file.readlines()
        for row in range(len(file_rows)): # row = 0,1,2,3,4,5
            file_rows[row] = file_rows[row].strip("\n")
            for column in range(len(file_rows[row])): # column 0,1,2,3,4........
                if (int(file_rows[row][column]) != 1):
                    for row_temp in range(row-1,row+2):
                        for column_temp in range(column-1,column+2):
                            try:
                                if(row_temp == -1 or column_temp == -1 or (row == row_temp and column == column_temp)):
                                    raise KeyError
                                if(  int(file_rows[row_temp][column_temp]) != 1):
                                    graph.add_edge(str(row)+","+str(column),str(row_temp)+","+str(column_temp),
                                                   float("{:.2f}".format(math.sqrt(math.pow(row-row_temp,2)+math.pow(column-column_temp,2)))))
                            except:
                                pass

        start_time = time.time()
        traced_path, cost = graph.uniform_cost_search(start, goal,output)
        if (traced_path): output.write('Path: '); UCSGraph.print_path(traced_path, goal,output); output.write('\nCost:'+str(cost)+"\n")
        output.close()
        return time.time() - start_time
    except KeyError:
        print("Start Location not found")
        return time.time() - start_time


# In[11]:


def run2(args):
    #dict = {"astar":[],"bfs":[],"dfs":[],"ucs":[]}
    for i in range(len(args)):
        start_node, goal_node = create_file2("Test {}".format(i), args[i])
        print("Start coordinate :"+start_node+
              "\nEnd coordinate :"+goal_node)
        try:
            astar_tuple = data_astar_nodes("Test {}".format(i), start_node, goal_node,"Test {}-astar".format(i)),args[i]
            #dict["astar"].append(tuple)
            print("astar : " + str(astar_tuple[1]) + "x" + str(astar_tuple[1])  + "-> runtime = " + str(astar_tuple[0]))
        except:
            print("Unexpected error for Astar:", sys.exc_info()[0])
        try:
            bfs_tuple = data_bfs_nodes("Test {}".format(i), start_node, goal_node,"Test {}-bfs".format(i)),args[i]
            #dict["bfs"].append(tuple)
            print("bfs : " + str(bfs_tuple[1]) + "x" + str(bfs_tuple[1])  + "-> runtime = " + str(bfs_tuple[0]))
        except:
            print("Unexpected error for BFS:", sys.exc_info()[0])
        try:
            dfs_tuple = data_dfs_nodes("Test {}".format(i), start_node, goal_node,"Test {}-dfs".format(i)),args[i]
            #dict["dfs"].append(tuple)
            print("dfs : " + str(dfs_tuple[1]) + "x" + str(dfs_tuple[1]) + "-> runtime = " + str(dfs_tuple[0]))
        except:
            print("Unexpected error for DFS:", sys.exc_info()[0])
        try:
            ucs_tuple = data_ucs_nodes("Test {}".format(i), start_node, goal_node,"Test {}-ucs".format(i)),args[i]
            #dict["ucs"].append(tuple)
            print("ucs : " + str(ucs_tuple[1]) + "x" + str(ucs_tuple[1])  + "-> runtime = " + str(ucs_tuple[0]))
        except:
            print("Unexpected error for UCS:", sys.exc_info()[0])

        print("------------------")


# recursion error = not complete olması

# In[18]:


run2([
    100,200,300,400
])


# # EXPERIMENTS FOR PROBLEM 1
# 
# For experimenting Problem 1, i have created four different square maps with(100x100, 200x200, 300x300, 400x400) sizes.<br>
# <br>For 100x100 i got these results: <br>
# <br>
# Start coordinate :98,94<br>
# End coordinate :2,76<br>
# astar : 100x100-> runtime = 0.531376838684082<br>
# bfs : 100x100-> runtime = 0.07905411720275879<br>
# dfs : 100x100-> runtime = 0.11107897758483887<br>
# ucs : 100x100-> runtime = 1.0297324657440186<br>
# 
# <br>For 200x200 i got these results: <br><br>
# Start coordinate :172,40<br>
# End coordinate :158,102<br>
# astar : 200x200-> runtime = 0.16811895370483398<br>
# bfs : 200x200-> runtime = 0.12609100341796875<br>
# dfs : 200x200-> runtime = 0.09907031059265137<br>
# ucs : 200x200-> runtime = 1.5641107559204102<br>
# 
# <br>For 300x300 i got these results: <br><br>
# Start coordinate :39,69<br>
# End coordinate :219,59<br>
# astar : 300x300-> runtime = 5.941223382949829<br>
# bfs : 300x300-> runtime = 1.0207266807556152<br>
# Unexpected error for DFS: <class 'RecursionError'><br>
# ucs : 300x300-> runtime = 12.834121704101562<br>
# 
# <br>For 400x400 i got these results: <br><br>
# Start coordinate :352,180<br>
# End coordinate :248,13<br>
# astar : 400x400-> runtime = 5.243725776672363<br>
# bfs : 400x400-> runtime = 2.0754759311676025<br>
# Unexpected error for DFS: <class 'RecursionError'><br>
# ucs : 400x400-> runtime = 40.0834858417511<br>
# 
# ## ANALYSIS FROM EXPERIMENT 1
# 
# ### How do we evaluate and compare search algorithms?
# 
# * **Completeness** : Is it guaranteed to find a solution (if one exists)?
# * **Optimality** : Does it find the “best” solution (if there are more than one)?
# * **Time Complexity** : How long does it take to find a solution?
# * **Space Complexity** : How much memory does it require?
# 
# #### Completeness
# 
# From these experiment results, we can see that all three algorithms except Depth First Search algorithm always guarantees a solution(optimal or not).But in same cases, depth first search algorithm gives Recursion Error to us.This means all three except Depth First Search algorithm are complete.
# 
# #### Optimality
# 
# There can be multiple solutions but which algorithm/s can choose the best solution?. To find this i have tested my algorithms and i will compare the paths they found.
# 
# **Path for A* Search:** 32,35 =>31,35 =>30,35 =>29,34 =>29,33 =>28,32 =>27,32 =>26,31 =>25,32 =>24,33 =>23,34 =>22,34 =>21,35 =>20,36 =>19,36 =>18,36 =>17,37 =>16,38 =>16,39 =>15,40 =>14,40 =>13,41 =>12,42 =>12,43 =>13,44<br>
# **Cost**:29.740000000000002
# 
# **Path for BFS:** 32,35 =>31,35 =>30,35 =>29,34 =>29,33 =>28,32 =>27,31 =>26,31 =>25,32 =>24,33 =>23,34 =>22,34 =>21,34 =>20,35 =>19,36 =>18,36 =>17,37 =>16,38 =>16,39 =>15,40 =>14,40 =>13,41 =>14,42 =>14,43 =>13,44
# 
# **Path for DFS:** 32,35 =>31,35 =>30,35 =>29,34 =>29,33 =>30,32 =>31,31 =>32,31 =>33,32 =>34,33 =>34,34 =>35,35 =>34,36 =>33,37 =>32,37 =>31,38 =>30,38 =>29,39 =>28,38 =>27,39 =>26,40 =>25,39 =>24,40 =>23,41 =>22,40 =>21,41 =>20,40 =>20,39 =>19,38 =>19,37 =>18,36 =>17,36 =>16,37 =>15,38 =>14,38 =>13,39 =>13,40 =>13,41 =>12,42 =>11,41 =>10,41 =>9,42 =>9,43 =>9,44 =>10,45 =>10,46 =>11,47 =>12,48 =>13,47 =>13,46 =>13,45 =>13,44
# 
# **Path for UCS:** 32,35 =>31,35 =>30,35 =>29,34 =>29,33 =>28,32 =>27,32 =>26,31 =>25,32 =>24,33 =>23,33 =>22,34 =>21,34 =>20,35 =>19,36 =>18,36 =>17,37 =>16,38 =>16,39 =>15,40 =>14,40 =>13,41 =>12,42 =>12,43 =>13,44<br>
# **Cost**:29.740000000000002
# 
# **As we see here, A* search and UCS finds the optimal solution with same cost but BFS and DPS finds solution but these solutions are not optimal.I have tried the same map and what i have found is, if the cost between nodes are all equal(sometimes becomes 1 instead of sqrt(2)) the BFS gives the optimal solution.**
# 
# **Path for A* Search:** 7,14 =>8,15 =>9,14 =>10,14 =>11,15 =>12,16 =>13,16 =>14,17 =>15,17 =>16,17 =>17,17 =>18,18 =>19,19 =>20,20 =>21,20 =>22,20 =>23,21 =>24,22 =>25,23 =>26,24 =>27,25 =>28,26 =>29,27 =>30,28 =>31,28 =>32,27 =>33,26 =>34,26 =>35,25 =>36,24 =>37,23 =>38,22 =>39,21 =>40,20 =>40,19 =>39,18 =>39,17 =>40,16 =>41,15 =>42,14 =>41,13<br>
# **Cost**:51.88999999999996
# 
# **Path for BFS:** 7,14 =>8,15 =>9,14 =>10,14 =>11,15 =>12,16 =>13,16 =>14,17 =>15,17 =>16,17 =>17,17 =>18,18 =>19,19 =>20,20 =>21,20 =>22,21 =>23,21 =>24,22 =>25,23 =>26,24 =>27,25 =>28,26 =>29,27 =>30,28 =>31,28 =>32,27 =>33,26 =>34,26 =>35,25 =>36,24 =>37,23 =>38,22 =>39,21 =>40,20 =>40,19 =>39,18 =>40,17 =>40,16 =>41,15 =>42,14 =>41,13<br>
# 
# **Path for DFS:** 7,14 =>7,15 =>6,16 =>5,16 =>4,16 =>3,17 =>2,18 =>3,19 =>2,20 =>1,20 =>0,21 =>1,22 =>0,23 =>1,24 =>2,24 =>3,24 =>4,24 =>5,25 =>5,26 =>4,27 =>3,27 =>2,27 =>1,28 =>1,29 =>2,30 =>3,31 =>4,31 =>5,31 =>6,31 =>7,30 =>8,29 =>7,28 =>8,27 =>7,26 =>8,25 =>9,25 =>10,24 =>9,23 =>8,23 =>7,22 =>8,21 =>7,20 =>8,19 =>9,19 =>10,19 =>11,20 =>12,21 =>12,22 =>13,23 =>14,22 =>14,21 =>15,20 =>16,21 =>17,21 =>18,20 =>19,19 =>20,20 =>21,20 =>22,20 =>23,21 =>24,22 =>25,23 =>26,24 =>27,25 =>28,26 =>27,27 =>27,28 =>28,29 =>27,30 =>26,31 =>26,32 =>25,33 =>25,34 =>25,35 =>26,36 =>25,37 =>24,38 =>23,39 =>22,40 =>21,39 =>20,40 =>19,39 =>18,39 =>17,38 =>16,37 =>16,36 =>15,35 =>16,34 =>16,33 =>17,32 =>18,31 =>17,30 =>16,30 =>15,31 =>14,30 =>13,29 =>12,30 =>11,31 =>11,32 =>10,33 =>9,33 =>8,34 =>9,35 =>9,36 =>10,37 =>11,38 =>12,38 =>13,38 =>14,38 =>15,39 =>16,40 =>17,41 =>18,42 =>17,43 =>17,44 =>16,45 =>15,44 =>14,45 =>13,44 =>12,43 =>11,44 =>10,44 =>9,45 =>10,46 =>11,47 =>12,48 =>13,49 =>14,48 =>15,48 =>16,48 =>17,49 =>18,48 =>19,48 =>20,49 =>21,48 =>21,47 =>21,46 =>20,45 =>19,44 =>20,43 =>21,43 =>22,44 =>23,44 =>24,44 =>25,43 =>26,44 =>27,43 =>28,43 =>29,43 =>30,42 =>30,41 =>31,40 =>31,39 =>30,38 =>30,37 =>31,36 =>32,37 =>33,36 =>33,35 =>32,34 =>32,33 =>33,32 =>34,32 =>35,31 =>36,32 =>36,33 =>37,34 =>38,35 =>38,36 =>38,37 =>39,38 =>39,39 =>39,40 =>40,41 =>41,41 =>42,40 =>43,41 =>44,40 =>44,39 =>45,38 =>45,37 =>44,36 =>43,37 =>42,37 =>41,36 =>42,35 =>43,34 =>43,33 =>44,32 =>43,31 =>44,30 =>43,29 =>42,29 =>41,28 =>42,27 =>41,26 =>40,25 =>39,24 =>39,23 =>38,22 =>37,23 =>37,24 =>36,25 =>35,26 =>35,27 =>35,28 =>34,29 =>33,29 =>32,29 =>31,28 =>32,27 =>33,26 =>33,25 =>32,24 =>33,23 =>34,22 =>34,21 =>33,20 =>34,19 =>33,18 =>34,17 =>35,16 =>34,15 =>33,14 =>32,13 =>33,12 =>33,11 =>33,10 =>33,9 =>34,8 =>35,8 =>36,9 =>35,10 =>36,11 =>37,12 =>38,12 =>39,13 =>40,12 =>41,13
# 
# **Path for UCS:** 7,14 =>8,15 =>9,14 =>10,14 =>11,15 =>12,16 =>13,16 =>14,17 =>15,17 =>16,17 =>17,17 =>18,18 =>19,19 =>20,20 =>21,20 =>22,20 =>23,21 =>24,22 =>25,23 =>26,24 =>27,25 =>28,26 =>29,27 =>30,28 =>31,28 =>32,27 =>33,26 =>34,26 =>35,25 =>36,24 =>37,23 =>38,22 =>39,21 =>40,20 =>40,19 =>39,18 =>39,17 =>40,16 =>41,15 =>42,14 =>41,13<br>
# **Cost**:51.88999999999996
# 
# 
# **From this we can say, A* Search and UCS are optimal, BFS can sometimes be optimal, DFS is not optimal.**
# 
# 
# #### Time Complexity
# 
# * **Branching Factor(b)**: In computing, tree data structures, and game theory, the branching factor is the number of children at each node, the outdegree. If this value is not uniform, an average branching factor can be calculated.Maximum braching factor of the search tree.
# 
# * **Depth(d)**: The depth of a node is the number of edges from the node to the tree's root node.Depth of the optimal solution.
# 
# * **C***: Cost of the optimal solution
# 
# * **m**: Maximum depth of search space<br><br>
# 
# * **BFS:** O($b^d$)
# * **UCS:** Number of nodes with g(n) <= C*
# * **DFS:** O($b^m$)
# * **A*:** Number of nodes with g(n) <= C*
# 
# In my experiment, Uniform Cost Search took the most time almost everytime, A* is faster than UNS and BFS was constantly the fastest.DFS was giving error on large scale problems but when it doesn't it was between UCS and A*.
# 
# 
# #### Space Complexity 
# 
# * **Branching Factor(b)**: In computing, tree data structures, and game theory, the branching factor is the number of children at each node, the outdegree. If this value is not uniform, an average branching factor can be calculated.Maximum braching factor of the search tree.
# 
# * **Depth(d)**: The depth of a node is the number of edges from the node to the tree's root node.Depth of the optimal solution.
# 
# * **C***: Cost of the optimal solution
# 
# * **m**: Maximum depth of search space<br><br>
# 
# * **BFS:** O($b^d$)
# * **UCS:** Number of nodes with g(n) <= C*
# * **DFS:** O(b.m)
# * **A*:** Number of nodes with g(n) <= C*
# 
# <img style="float: left;" src="space.png"> 
# 

# ### <center>Another Creative Example For Problem 1
#     
# In this problem we have a map and rows represents cities and columns are neighbors of that city(diagonals are the cities with themselves) I have shown neighbors with 0 and not neighbors with 1 but we have a problem. In this map some of the cities are effected by coronavirus, so if we want to go from point A to point B we can't use the cities effected by coronavirus.
# 
# In this example 
# 
# My map is the same map from above. It is randomly generated , every coordinate is represented as nodes, we have one starting node(randomly generated) this represent starting city and a finish node(randomly generated) this represent where the target city.Driver's aim is to go to target without visiting cities effected by coronavirus.And for this we have randomly generated list of cities effected by coronavirus.
# 
# 
# For creating a map , I create a square map with given size, for this experiment i will be using 100, 200, 300 and 400 to compare my algorithms.

# # EXPERIMENTS FOR ANOTHER EXAMPLE ON PROBLEM 1
# 
# For experimenting Problem 1, i have created four different square maps with(100x100, 200x200, 300x300, 400x400) sizes.<br>
# 
# 
# **Corona List** = [0, 185, 136, 275, 159, 143, 192, 188, 39, 174, 187, 182, 171, 202, 168, 94, 157, 166, 138, 229, 42, 160, 9, 105, 10, 196, 234, 107, 280, 10]<br>
# Start coordinate :275,44<br>
# End coordinate :267,214<br>
# 
# astar : 300x300-> runtime = 0.9166512489318848<br>
# bfs : 300x300-> runtime = 0.08203816413879395<br>
# dfs : 300x300-> runtime = 6.033273696899414<br>
# ucs : 300x300-> runtime = 0.8325905799865723<br>
# 
# **Corona List** = [188, 217, 198, 378, 163, 251, 126, 83, 194, 144, 66, 346, 322, 177, 42, 201, 324, 231, 156, 334, 28, 59, 229, 386, 332, 326, 56, 315, 272, 77, 105, 244, 369, 330, 77, 222, 97, 273, 216, 263]<br>
# Start coordinate :11,89<br>
# End coordinate :103,347<br>
# 
# astar : 400x400-> runtime = 0.129018402099609375<br>
# bfs : 400x400-> runtime = 0.10400233268737793<br>
# dfs : 400x400-> runtime = 26.26977562904358<br>
# ucs : 400x400-> runtime = 1.4102897644042969<br>
# 
# **Corona List** = [209, 324, 63, 480, 473, 302, 390, 63, 107, 161, 146, 20, 278, 417, 48, 100, 263, 168, 465, 245, 431, 241, 42, 461, 76, 361, 29, 385, 12, 205, 359, 217, 76, 215, 12, 176, 365, 250, 436, 249, 304, 178, 481, 361, 114, 118, 396, 213, 97, 467]<br>
# Start coordinate :10,390<br>
# End coordinate :70,392<br>
# 
# astar : 500x500-> runtime = 6.824112640742357<br>
# bfs : 500x500-> runtime = 3.1357892345621684<br>
# dfs : 500x500-> runtime = 74.80299186706543<br>
# ucs : 500x500-> runtime = 15.689256267815321<br>
# 
# 
# **Corona List** = [19, 28, 434, 117, 36, 515, 197, 254, 542, 504, 341, 180, 594, 479, 231, 86, 575, 482, 581, 556, 124, 423, 421, 346, 439, 121, 545, 559, 566, 591, 64, 501, 345, 178, 387, 319, 12, 505, 399, 5, 149, 110, 599, 196, 450, 224, 462, 321, 446, 286, 326, 497, 588, 351, 283, 327, 585, 263, 332, 351]<br>
# Start coordinate :205,372<br>
# End coordinate :571,50<br>
# 
# astar : 600x600-> runtime = 12.12438509812367<br>
# bfs : 600x600-> runtime = 3.9543874321490<br>
# dfs : 600x600-> runtime = 54.11534833908081<br>
# ucs : 600x600-> runtime = 17.4451236015148<br>
# 
# Our analysis is same as above, just wanted to test another creative example for problem 1.But our paths are too long to paste here.
# 
# <img style="float: left;" src="space2.png"> 

# ### <center> Problem 2
# 
# For problem 2, i choose 8 puzzle problem.My scenario is, our computer got hacked by Hacettepe CS student and he/she encrypted our photos with 8 puzzle problem and she/he also encrypted our sister's favorite photo if she sees encrypted photo, she will be upset and hearthbroken to see her favorite photo in that mess, and she is coming to our room you can hear her footsteps.From footsteps we assume we have 5 seconds to solve this mess.Can you select the correct search algorithm for this? or will you see your sister sad?
# 
# 
# Basically 8 puzzle proglem is puzzle isgiven a 3×3 board with 8 tiles (every tile has one number from 1 to 8) and one empty space. The objective is to place the numbers on tiles to match final configuration using the empty space. We can slide four adjacent (left, right, above and below) tiles into the empty space.
# 
# Goal:        Easy:        Medium:        Hard:        Worst:
# 
# 1 2 3        1 3 4        2 8 1          2 8 1          8 7
# 4 5 6        8 6 2          4 3          4 6 3        6 5 4
# 7 8          7   5        7 6 5            7 5        3 2 1

# https://github.com/chitholian/AI-Search-Algorithms
# https://sites.cs.ucsb.edu/~yuxiangw/classes/CS165A-2019winter/Lectures/Lecture-11.pdf
# https://en.wikipedia.org/wiki/A*_search_algorithm
# https://math.wikia.org/wiki/Uniform_cost_search
# https://en.wikipedia.org/wiki/Breadth-first_search
# https://en.wikipedia.org/wiki/Depth-first_search
# https://images.slideplayer.com/31/9777163/slides/slide_7.jpg
# https://slideplayer.com/slide/1512813/
# https://slideplayer.com/slide/1512813/5/images/59/Comparison+of+search+strategies.jpg
# https://www.geeksforgeeks.org/8-puzzle-problem-using-branch-and-bound/
# https://www.d.umn.edu/~jrichar4/8puz.html
# https://github.com/speix/8-puzzle-solver
