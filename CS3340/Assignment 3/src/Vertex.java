import java.util.HashMap;
import java.util.Map;

/**
 * @author name - Student ID: xxxxxxxxx
 * CS3340 Assignment 3**/
public class Vertex {
	
	private String vertName = null;
	private Map<Vertex, Edge> edges = new HashMap<>();
	private boolean visited = false;
	
	public Vertex(String name) {
		vertName = name;
		visited = false;
	}
	
	public void setEdge(Vertex v, Edge e) {
		edges.put(v, e);
	}
	
	public String getVertName() {
		return vertName;
	}
	
	public Map<Vertex, Edge> getEdges(){
		return edges;
	}
	
	public boolean getVisitStatus() {
		return visited;
	}
	
	public void markVisited() {
		visited = true;
	}

}
