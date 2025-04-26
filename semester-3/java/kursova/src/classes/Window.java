package classes;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.LinkedList;

public class Window extends JFrame {
	enum Shape { filledOval, rectangle, oval };
	
	Shape shape = Shape.filledOval;
	Color color = Color.BLACK;
	boolean mousePressed = false;
	
	LinkedList<DrawableShape> shapeStorage = new LinkedList<DrawableShape>();
	int startingX;
	int startingY;
	
	public Window() {	
		setTitle("Bad");
		setSize(600, 400);	
		setResizable(false);
		
        setJMenuBar(createMenuBar());
		add(createCanvas());
        
        setVisible(true);
	}
	
	public JPanel createCanvas() {
		JPanel canvas = new JPanel() {
			@Override
			public void paint(Graphics g) {
				g.setColor(Color.WHITE);
				g.fillRect(0, 0, getWidth(), getHeight());
				
				shapeStorage.forEach((DrawableShape s) -> {s.drawShape(g);});
			}
		};
		
		registerEvents(canvas);
		
		return canvas;
	}
	
	public void registerEvents(JPanel canvas) {
		canvas.addMouseListener(new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent e) {
				startingX = e.getX();
				startingY = e.getY();
				
				DrawableShape tmp = switch (shape) {
					case filledOval -> new FilledOval(startingX, startingY, startingX, startingY, color);
					case oval -> new Oval(startingX, startingY, startingX, startingY, color);
					case rectangle -> new Rectangle(startingX, startingY, startingX, startingY, color);
				};
				
				shapeStorage.addLast(tmp);
				mousePressed = true;
			}

			@Override
			public void mouseReleased(MouseEvent e) {
				mousePressed = false;
			}
		});
		
		canvas.addMouseMotionListener(new MouseMotionAdapter() {
			@Override
			public void mouseDragged(MouseEvent e) {
				if (!mousePressed) return;
		
				shapeStorage.getLast().move(startingX, startingY, e.getX(), e.getY());
				
				repaint();
			}
		});
	}
	
	public JMenuBar createMenuBar() {		
        JMenuBar mb = new JMenuBar();		
		JMenu shapesMenu = new JMenu("Shapes");
		JMenu colorsMenu = new JMenu("Colors");
		JMenu functions = new JMenu("Functions");
		
		JMenuItem filledOval = new JMenuItem("Oval");
		JMenuItem oval = new JMenuItem("Empty oval");
		JMenuItem rectangle = new JMenuItem("Empty rectangle");
		
		//set global shape variable
		filledOval.addActionListener(e -> shape = Shape.filledOval);
		oval.addActionListener(e -> shape = Shape.oval);
		rectangle.addActionListener(e -> shape = Shape.rectangle);
		
		JMenuItem clBlack = new JMenuItem("Black");
		JMenuItem clRed = new JMenuItem("Red");
		
		//set global color variable
		clBlack.addActionListener(e -> color = Color.BLACK);
		clRed.addActionListener(e -> color = Color.RED);
		
		JMenuItem print = new JMenuItem("Print");
		print.addActionListener(e -> {	
			shapeStorage.forEach((DrawableShape s) -> System.out.println(shapeStorage.indexOf(s) + ". " + s.toString()));
		});
		
	    shapesMenu.add(filledOval);
		shapesMenu.add(oval);
	    shapesMenu.add(rectangle);
	    
	    colorsMenu.add(clBlack);
	    colorsMenu.add(clRed);
	    
	    functions.add(print);
		
	    mb.add(shapesMenu);
	    mb.add(colorsMenu);
	    mb.add(functions);
	    
		return mb;
	}
}