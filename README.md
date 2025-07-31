#Metro Station Navigator

A C-based console application to simulate and query a **metro rail network** using **graph algorithms**. It allows users to search for metro stations, compute distances, estimate travel times and costs, and find shortest paths between stations in a metropolitan city.

---

##Features

- View list of all metro stations
- Find shortest distance between two stations
- Estimate travel time and fare between two stations
- Display station-to-station network (multiple destinations)
- Count number of stations between source and destination
- Show estimated travel duration based on real-world assumptions

---


---

##How It Works

- The metro map is modeled using an **adjacency matrix** representation of a graph.
- Nodes represent **stations**, and edges represent **routes** with weights indicating distance (in meters).
- It implements **Dijkstra’s algorithm** for finding shortest paths.
- Uses real-time input from users to query different functionalities via a menu-based interface.

---

##Setup & Compilation

### 🔹 Requirements

- A C compiler (e.g., GCC)
- Terminal/console access

### 🔹 Compile

```bash
gcc metro-station.c -o metro

./metro

menu options:

Enter 1 for source to destination
Enter 2 for single source to multiple destination
Enter 3 for number of stations between source and destination
Enter 4 for number of stations from source to all
Enter 5 for detailed tour (cost, time)
Enter 6 for path between source and destination
Enter 7 for distance to all in sorted order
Enter 0 to exit

sample stations :
1. LBnagar
2. Victoria_memorial
3. Chaitanyapuri
...
55. Hitechcity
56. Raidurg
