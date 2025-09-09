import graph;
size(10cm);

// đọc dữ liệu 2 cột (x, y) từ file orbit.dat
real[][] data = readfile("orbit.dat");

// hoặc, nếu orbit.dat có nhiều cột, chọn cột x và y
// pair[] pts = readfile("orbit.dat", 1, 2);
draw(graph(data), blue+1bp);

dot((0,0), red); // Mặt trời ở gốc tọa độ
label("$x$", (1.1,0), E);
label("$y$", (0,1.1), N);
