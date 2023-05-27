void main() {
char x[64];
long int* y = (long int*)x;

for (long int i = 0; i < 8; i++) {
	*y = i;
	y++;
}
int* z = (int*)x;
for (int i = 0; i < 16; i++) {
	*z = i;
	z++;
}

}
