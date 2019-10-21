import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import org.jgrapht.Graph;
import org.jgrapht.alg.shortestpath.DijkstraShortestPath;
import org.jgrapht.graph.DefaultWeightedEdge;

import org.jgrapht.graph.SimpleWeightedGraph;
import org.jgrapht.io.Attribute;
import org.jgrapht.io.EdgeProvider;
import org.jgrapht.io.GmlImporter;
import org.jgrapht.io.ImportException;
import org.jgrapht.io.VertexProvider;

public class Main {

	@SuppressWarnings({ "unchecked", "static-access" })
	public static void main(String[] args) {
	

	FileReader arg1 = null;
	try {
		 arg1=new FileReader("src\\test_graph.gml");
	} catch (FileNotFoundException e1) {
		// TODO Auto-generated catch block
		e1.printStackTrace();
		}
	
	Graph<String, DefaultWeightedEdge> g=new SimpleWeightedGraph<String, DefaultWeightedEdge>(DefaultWeightedEdge.class);

	VertexProvider<String> vp = new VertexProvider<String>()
	        {
				@Override
				public String buildVertex(String label, Map<String, Attribute> attributes) {
					return label;
				}

				
	        };

	        EdgeProvider<String, DefaultWeightedEdge> ep = new EdgeProvider<String, DefaultWeightedEdge>()
	        {

	   			@Override
				public DefaultWeightedEdge buildEdge(String from, String to, String label, Map<String, Attribute> attributes) {
					return g.getEdgeFactory().createEdge(from, to);
				}

	        };

	        
	  // importing GML File
	        
	        GmlImporter<String, DefaultWeightedEdge> importer = new GmlImporter<String, DefaultWeightedEdge>(vp, ep);
	        try {
				importer.importGraph(g, arg1);
				System.out.println("THE GRAPG IS SUCCESFULLY IMPORTED");
			} catch (ImportException e) {
				e.printStackTrace();
			}
	 //Creating dijkstra instance from our graph g
	        
	DijkstraShortestPath<String, DefaultWeightedEdge> dijkistra = new DijkstraShortestPath<String, DefaultWeightedEdge>(g);
	
	@SuppressWarnings("rawtypes")
	List list = new ArrayList(g.vertexSet());

    
         Integer[]  betweenness_centrality_counter = new Integer[g.vertexSet().size()];
         for(int i = 0 ; i < betweenness_centrality_counter.length;i++) 
        	 betweenness_centrality_counter[i]=0;
        
          //conputing betweenness_centrality_counter
         
	        for(String i : g.vertexSet()) {
	        	System.out.println("this is the shortest path from "+i+" to the rest of the nodes");
	        	for(int s = list.indexOf(i) ;s<g.vertexSet().size();s++ ) {
	        		System.out.println(i +" to "+ (s+1) +" is : " +dijkistra.findPathBetween(g, i, String.valueOf(s+1)));
	        		//incremente counting
	        		for(String vertex : dijkistra.findPathBetween(g, i, String.valueOf(s+1)).getVertexList()) {
	        			betweenness_centrality_counter[Integer.valueOf(vertex)-1]+=1;
	        		}
	        	}
	        	
	        }
	
	        
	   System.out.println("betweennes centrality  of each node is : ");     
	   for(int i = 0 ;i<betweenness_centrality_counter.length;i++)
		   System.out.println("node "+(i+1)+" => "+betweenness_centrality_counter[i]);
	  
	        
	}

}
