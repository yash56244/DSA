int Add(int x, int y)
{
    if (y == 0)
        return x;
    else
        return Add( x ^ y, (x & y) << 1);
}
 // Another Method using half adder logic.
int add(int x, int y){
	int sum, carry;
	while(y ! = 0){
		sum = x ^ y;
		carry (x & y) << 1;
		x = sum;
		y = carry;
	}
	return x;
}
