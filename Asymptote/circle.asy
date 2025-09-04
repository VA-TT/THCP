size(12cm, keepAspect=true); // size of the picture 12x12
defaultpen(fontsize(16pt)); // fontsize
pen p1 = red + linewidth(1);// define a variable p1 = red+linewidth=1
pen p2 = blue + linewidth(1);// p1 used as a pen to draw figures
real a = 0.5*(sqrt(5)-3);
real b = 1 + a;
real c = sqrt(1-b);
real d = 0.5b;
pair O = (0,0); pair O1 = (0,a); pair O2 = (0,b); pair O3 = (c,d); pair O4 = (-c,d);
draw(circle(O,1),p1); // draw a circle centered at O, radius=1
filldraw(circle(O1,1+a),opacity(0.9)+pink, p2);