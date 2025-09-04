size(12cm, keepAspect=true); // size of the picture 12x12
defaultpen(fontsize(16pt)); // fontsize
pair A = (-1,0); // define a ``pair'' variable named A, with value (-1,0)
pair B = ( 1,0);
pair C = ( 1,2);
pair D = (-1,2);
pair O = ( 0,0);
pen p1 = red + linewidth(1);// define a variable p1 = red+linewidth=1
pen p2 = blue + linewidth(1);// p1 used as a pen to draw figures
draw(A--B--C--D--cycle, p1); // draw a line joining ABCDA, with pen = p1
draw(arc(O,1.,0., 180.),p2); // draw an arc centered at O, rad=1
draw(arc(A,2.,0., 90. ),p2); // starting angle =0, ending angle=180
draw(arc(B,2.,90.,180.),p2); // with pen `p2'(comment for first draw)


real myfunc(real x)
{
return 8*x^3 - 4*x^2 - 3*x + 1;
}
real epsilon = 1e-10; // tolerance of the method
real bisection(real a, real b, real f(real))
{
real fa = f(a);
real x = 0.5*(a+b);
if
( abs(f(x)) < epsilon ){ // if f(x) so small: x is the solution
return x;
}
else if ( fa * f(x) > 0 ){
// check [x,b]
return bisection(x,b,f);
}
else {
return bisection(a,x,f);
// check [a,x]
}
}
real xx = bisection(0,0.5,myfunc); // use the function
write(xx);
// print the result to screen

real yy = sqrt(4-(xx+1)^2);
pair A1 = (-xx,yy-2*xx);
pair B1 = ( xx,yy-2*xx);
pair C1 = ( xx,yy
);
pair D1 = (-xx,yy
);
filldraw(A1--B1--C1--D1--cycle, opacity(0.5)+pink ,p1);
dot(O); label("$O$", O,S); // draw a point at O, with a label below it