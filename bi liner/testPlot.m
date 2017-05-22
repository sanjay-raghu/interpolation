//plot(z);
//axis([0 1000 -1 1]);
//grid on;
//title(sprintf('a = %0.3f \t b = %0.3f',a,b));
//pause(0.1);
x = 1:a;
y = 1:b;
[X,Y] = meshgrid(x,y);

IZ= sin(X)+cos(Y);
DZ= IZ-Z ;

surf(Z);
surf(IZ);
surf(DZ);
