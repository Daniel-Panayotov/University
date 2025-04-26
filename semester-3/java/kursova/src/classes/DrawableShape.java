package classes;
import java.awt.Graphics ;

public interface DrawableShape {
	void drawShape (Graphics g);
	void move (int x1 , int y1 , int x2 , int y2);
}