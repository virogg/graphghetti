# Graphghetti _or Graph Vizualization Algorithm_ 
## Introduction
A graph **_G = (V, E)_** is a set **_V_** of vertices and a set **_E_** of edges, in which an edge joins a pair of vertices. Normally, graphs are depicted with their vertices as points in a plane and their edges as line or curve segments connecting those points. There are different styles of representation, suited to different types of graphs or different purposes of presentation. We concentrate on the most general class of graphs: **undirected graphs, drawn with straight edges**.

## Algorithm
A program has been implemented that allows generating images of undirected graphs specified by a list of edges based on the [Fruchterman-Reingold algorithm](https://reingold.co/force-directed.pdf).
The output image contains a minimum of vertex and edge overlays. In the image, the snowy peaks are close to each other, the non-adjacent ones are far away.

The Fruchterman-Reingold algorithm was chosen to implement the graph visualization problem because of its advantages: **simplicity**, **flexibility**, **strong theoretical foundations** and **interactivity**. Among the disadvantages of this algorithm, it is worth mentioning the **long-running time for a graph with a large number of vertices**.

Since it seems to favor "untangling" over random placements, the Fruchterman-Reingold version begins by placing all vertices on a circle. The circle's radius is always 1.0, and all following calculations are done using floating point values without taking the size of the canvas into account. As a result, no bound checking is carried out, in contrast to the original Fruchterman-Reingold algorithm, and the layout can spread without constraints. After that, the final output is scaled to match the canvas's dimensions.

## How to build
1. Clone the repository
```bash
git clone https://github.com/virogg/graphghetti.git
```
2. Change the directory to the folder
```bash
cd graphghetti
```
3. Create `build` folder
```bash
mkdir build && cd build
```
4. Use `cmake` to build the project
```bash
cmake .. && make
```


## Input and Output
The program handles different input parameters:
1. `-input` — input path to the file with vertices. **Required parameter**
2. `-output` — output path. **Required parameter**
3. `-width` — width of an output image. Default value is 1000px;
4. `-height` — height of an output image. Default value is 1000px;
5. `-iter` — number of iterations of the algorithm. Default value is 1000;

### Input example
```bash
./graphghetti -input "../samples/bamboo_graph.txt" -output "../samples/bamboo_graph.bmp" -width 1280 -height 720
```

The result of the program is an image in a `.bmp` format:
- The vertices are indicated by circles with a diameter of 7 pixels.
- The vertices are signed, the signature font is 12 px.
- The edge length is at least 30 pixels.

## .bmp format
Since the file is saved in `.bmp`, several functions have been implemented:
- to create a blank canvas with specified width and height;
- to draw lines (see [Bresenham's line algorithm](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm));
- to draw circles of specified radius (7 px by default) and color (black by default);
- to draw digits of specified color (red by default) and font size (12 px);
- to save `.bmp` file;

## Example
| **INPUT**                                                                                                                                          | **OUTPUT**                                                                       |
|----------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------|
| 10 15 <br> 0 1 <br> 1 2 <br> 2 3 <br> 3 4 <br> 4 5 <br> 5 6 <br> 0 6 <br> 6 7 <br> 1 7 <br> 7 8 <br> 5 8 <br> 3 8 <br> 0 9 <br> 2 9 <br> 4 9       | ![](https://github.com/virogg/graphghetti/blob/main/samples/graph1.gif?raw=true) |

### You can see other examples in `/samples`!

## Literature
- [Fruchterman-Reingold algorithm](https://reingold.co/force-directed.pdf)
- [Bresenham's line algorithm](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm)
- [Force-directed graph drawing Wiki](https://en.wikipedia.org/wiki/Force-directed_graph_drawing)