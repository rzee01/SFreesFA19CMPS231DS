void sort_in_place(int &x, int &y, int &z)
{
	if (x > y) {
		int tmp = y;
		y = x;
		x = tmp;
	}

	if (y > z) {
		int tmp = z;
		z = y;
		y = tmp;
	}

	if (x > y) {
		int tmp = y;
		y = x;
		x = tmp;
	}
}
