using namespace std;

bool isPalindrome(string str) {
  int front = 0, end = str.length()-1;
	while (front < end) {
		if (str[front++] != str[end--])
			return false;
	}
  return true;
}