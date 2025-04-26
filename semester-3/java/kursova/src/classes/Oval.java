package classes;

import java.awt.Color;
import java.awt.Graphics;

public class Oval extends BaseShape implements DrawableShape {
	public Oval(int x1 , int y1 , int x2 , int y2 , Color fill_color ) {
		super(x1 , y1 , x2 , y2 , fill_color );
	}
	
	@Override
	public void drawShape(Graphics g) {
		g.setColor(color);
		g.drawOval(x_left, y_top, x_right - x_left, y_bottom - y_top);
	}

}
