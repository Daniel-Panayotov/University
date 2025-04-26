package classes;

import java.awt.Color;

public class BaseShape {
	int x_left;
	int y_top;
	int x_right;
	int y_bottom;
	
	Color color;
	
	public BaseShape (int x1, int y1, int x2, int y2, Color color) {
		this.x_left = Math.min(x1 , x2);
		this.y_top = Math.min(y1 , y2);
		this.x_right = Math.max(x1 , x2);
		this.y_bottom = Math.max(y1 , y2);
		this.color = color;
	}
	
	public void move(int x1, int y1, int x2, int y2) {
		this.x_left = Math.min(x1 , x2);
		this.y_top = Math.min(y1 , y2);
		this.x_right = Math.max(x1 , x2);
		this.y_bottom = Math.max(y1 , y2);
	}
	
	public String toString () {
		return this.getClass().getName()
			+ " #" + Integer.toHexString(this.color.getRGB())
			+ " (" + x_left + "," + y_top + ")"
			+ " (" + x_right + "," + y_bottom + ")";
	}
}
