// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>//Used only in some functions' definitions. Use the provided implementations of its functions instead.

#pragma warning(disable: 4996)//Disables "strcpy" warning, which has code "4996".

using namespace std;//It is not needed but could come in handy.

#define MAX 10//Macro that replaces the piece of code "MAX" with its value of 10.

#define MAX_SIZE 100//Macro that replaces the piece of code "MAX_SIZE" with its value of 100.

const int N = 4;//All constants are written in upper-case and this one here is a global. Meaning that they can be used in the entirety of the file.

unsigned strlen(char* str) {
	unsigned counter = 0;
	while (*str != '\0') {
		counter++;
		str++;
	}

	return counter;
}

void primes() {
	int lower, higher, flag, temporary;
	cout << "Please enter the two numbers for finding prime numbers between them: " << endl;
	cin >> lower >> higher;
	if (lower > higher) {    //It will swap the numbers if lower number is greater than higher number.
		temporary = lower;
		lower = higher;
		higher = temporary;
	}
	cout << "Hence the Prime numbers between the number " << lower << " and " << higher << " are: " << endl;
	while (lower < higher)
	{
		flag = 0;
		for (int x = 2; x <= lower / 2; ++x)
		{
			if (lower % x == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			cout << lower << " ";
		++lower;
	}
}

void leapYears() {
	int y;
	cout << "\nPlease, enter a leap year: ";
	cin >> y;

	if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)) {
		cout << "Leap year.\n";
	}
	else {
		cout << "Not a leap.\n";
	}
}

bool checkPalindrome(int number) {
	int reverse = 0;
	for (int i = number; i > 0; i /= 10) {
		reverse = reverse * 10 + i % 10;
	}

	return (reverse == number);
}

void palindromes() {
	
	int min;
	int max;

	cout << "Enter a 'min' and 'max' numbers respectively: ";
	cin >> min >> max;

	int counter = 0;

	for (int i = min; i <= max; i++) {

		if (checkPalindrome(i)) {
	
			cout << i << " ";
			counter++;
			
			if (counter % 10 == 0) {
				cout << endl;
			}
		}
	}

}

unsigned long long factorials(int n) {
	if (n == 0) {
		return 1;
	}

	return n * factorials(n - 1);
}

void fibonacciNumber(int n) {
	static int numberOne = 0, numberTwo = 1, numberThree;

	if (n > 0) {
		numberThree = numberOne + numberTwo;
		numberOne = numberTwo;
		numberTwo = numberThree;

		cout << numberThree << endl;

		fibonacciNumber(n - 1);
	}
}

void isStringPalindrome() {
	char str[20];
	cin >> str;
	
	int len = strlen(str);
	bool flag = 0;

	for (int i = 0; i < len; i++) {
		if (str[i] != str[len - i - 1]) {
			flag = 1;
			break;
		}
	}

	if (flag) {
		cout << "Not a palindrome." << endl;
	}
	else {
		cout << "Given string is palindrome." << endl;
	}
}

void starPattern() {
	cout << "Enter a whole positive number: ";
	int n;
	cin >> n;

	char type[30];
	cout << "Specify the type of star pattern\n >diamond\n >equilateral\n >left_acute\n >empty_diamond.\n";
	cin >> type;

	if (strcpy(type, "diamond")) {
		for (int i = 0; i <= n; i++)
		{
			for (int s = n; s > i; s--)
				cout << " ";
			for (int j = 0; j < i; j++)
				cout << "* ";
			cout << "\n";
		}
		for (int i = 1; i < n; i++)
		{
			for (int s = 0; s < i; s++)
				cout << " ";

			for (int j = n; j > i; j--)
				cout << "* ";

			cout << "\n";
		}
	}
	else if (strcpy(type, "equilateral")) {
		for (int i = 1; i <= n; i++) {
			for (int s = 1; s < n; s++) {
				cout << " ";
			}
			for (int j = 1; j <= 2 *i - 1; j++) {
				cout << "*";
			}
			cout << " ";
		}
	}
	else if (strcpy(type, "empty_diamond")) {
		int i, j, k, m = 1;
		
		for (i = 0; i <= n; i++)
		{
			for (j = n; j > i; j--)
			{
				cout << " ";
			}
			cout << "*";
			if (i > 0)
			{
				for (k = 1; k <= m; k++)
				{
					cout << " ";
				}
				m += 2;
				cout << "*";
			}
			cout << endl;
		}
		m -= 4;
		for (i = 0; i <= n - 1; i++)
		{
			for (j = 0; j <= i; j++)
			{
				cout << " ";
			}
			cout << "*";
			for (k = 1; k <= m; k++)
			{
				cout << " ";
			}
			m -= 2;
			if (i != n - 1)
			{
				cout << "*";
			}
			//ending line after each row
			cout << endl;
		}
	}
	else if (strcpy(type, "left_acute")) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				cout << "* ";
			}
			cout << "\n";
		}
	}
	else {
		cout << "Invalid input!" << endl;
	}
}

void insertionSort() {
	const size_t size = 10;
	int arr[size];
	
	cout << "The size of the array is: " << size << endl;

	//user input elements
	cout << "Enter all the elements.\n";
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	//sort elements in array
	for (int j = 0; j < size; j++) {
		int t = arr[j];
		int k = j - 1;

		while (k >= 0 && t <= arr[k]) {
			arr[k + 1] = arr[k];
			k = k - 1;
		}
		arr[k + 1] = t;
	}

	//print	elements
	cout << "\nSorted array listed as: \n";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "\t";
	}

}

void selectionSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}

		//swap(&arr[minIndex], &arr[i]);
	}
}

bool isLower(char ch) {
	return ch >= 'a' && ch <= 'z';
}

char* sortLowerChars(const char* str) {
	const int ALPHABET_SIZE = 26;
	int hist[ALPHABET_SIZE] = { 0 };
	int newSize = 0;

	while (*str != '\0') {
		if (isLower(*str)) {
			newSize++;
			hist[*str - 'a']++;
		}
		str++;
	}

	char* result = new char[newSize + 1];
	result[newSize] = '\0';
	int resultIndex = 0;

	for (int i = 0; i < ALPHABET_SIZE; i++) {
		while (hist[i] > 0) {
			result[resultIndex++] = 'a' + i;
			hist[i]--;
		}
	}

	return result;
}

void transposeSquareMatrix(int arr[N][N], unsigned size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			arr[i][j] = arr[j][i];
		}
	}
}

void transposeMatrix(int** arr, unsigned rows, unsigned cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = arr[j][i];
		}
	}
}

bool strcmp(char* str1, char* str2) {
	int counter = 0;
	//when the strings are equal strcmp returns 0 and vice versa
	if (strlen(str1) == strlen(str2)) {
		for (int i = 0; i < strlen(str1); i++) {
			if (str1[i] == str2[i]) {
				counter++;
			}
			else {
				return 1;
			}
		}

		if (counter == strlen(str1)) {
			return 0;
		}
	}
	
	return 1;
}

char* substr(const char* string, size_t startIndex, size_t lengthOfSubstring) {
	char* substrOfString = new char[lengthOfSubstring + 1];

	for (int i = startIndex; i < lengthOfSubstring; i++) {
		substrOfString[i] = string[i];
	}
	
	//delete[] string;

	return substrOfString;
}

void strcpy(char* stringCopy, char* stringCopied) {
	for (int i = 0; i < strlen(stringCopied); i++) {
		stringCopy[i] = stringCopied[i];
	}

	delete[] stringCopied;
	stringCopy = stringCopied;
}

void strcat(char* stringFirst, char* stringSecond) {
	int length = strlen(stringFirst) + strlen(stringSecond) + 1;
	char* temp = new char[length];
	for (int i = 0; i < strlen(stringFirst) + 1; i++) {
		temp[i] = stringFirst[i];
	}
	for (int j = 0; j < strlen(stringSecond) + 1; j++) {
		temp[strlen(stringFirst) + j] = stringSecond[j];
	}

	delete[] stringFirst, stringSecond;
	stringFirst = temp;
}

void stringToLower(char* str) {
	for (int i = 0; i < strlen(str) + 1; i++) {
		if (*(str + i) >= 'A' && *(str + i) <= 'Z') {
			*(str + i) -= 'A' - 'a';
		}
	}
}

void stringToUpper(char* str) {
	for (int i = 0; i < strlen(str) + 1; i++) {
		if (*(str + i) >= 'a' && *(str + i) <= 'z') {
			*(str + i) -= 'a' - 'A';
		}
	}
}

int pow(int number, int power) {
	if (power == 0 ) {
		return 1;
	}
	pow(number, power - 1);
}

int numberLength(int number) {
	int counter = 0;
	while (number) {
		counter++;
		number /= 10;
	}
	return counter;
}

unsigned int convertBinaryToDecimal(unsigned long long n) {

	int i = 0; 
	int decimalNumber = 0;
	int remainder;

	while (n) {
		remainder = n % 10;
		n /= 10;
		decimalNumber += remainder * pow(2, i);
		++i;
	}

	return decimalNumber;
}

unsigned long long convertDecimalToBinary(unsigned int n) {

	unsigned long long binaryNumber = 0;
	int remainder;
	int i = 1;

	while (n) {
		remainder = n % 2;
		n /= 2;
		binaryNumber += remainder * i;
		i *= 10;
	}
	return binaryNumber;
}

void insertElementInArray(int arr[], int size, int position, int elementNum) {
	if (position >= size + 1 || position <= 0) {
		cout << "Invalid position!\n";
		return;
	}
	
	for (int i = size; i >= position; i--) {
		arr[i] = arr[i - 1];
	}

	arr[position - 1] = elementNum;
	size++;
}

bool isPerfectNumber(int n) {
	int i, sum;

	for (i = 1; i < n; i++) {
		if (n % i == 0) {
			sum += i;
		}
	}

	/*If sum of proper positive divisors equals to given number
	  then the number is perfect number*/
	if (sum == n) {
		return true;
	}

	return false;
}

void printNumberInWords(int n) { 
	int remainder = 0;

	while (n) {
		remainder *= 10 + (n % 10);
	}

	//prints corresponding digits
	while (n) {
		switch (n % 10) {
		case 0: cout << "zero ";
			break;
		case 1: cout << "one ";
			break;
		case 2: cout << "two ";
			break;
		case 3: cout << "three ";
			break;
		case 4: cout << "four ";
			break;
		case 5: cout << "five ";
			break;
		case 6: cout << "six ";
			break;
		case 7: cout << "seven ";
			break;
		case 8: cout << "eight ";
			break;
		case 9: cout << "nine ";
			break;
		}
		n /= 10;
	}


}

long numberWithEvenDigits(long long n) {
	int currentD = 0;

	int i = 1;

	int evenN = 0;

	while (n) {
		currentD = n % 10;
		if (currentD % 2 == 0) {
			evenN += (currentD * i);
			i *= 10;
		}
		n /= 10;
	}

	return evenN;
}

//PPDI or Armstrong number
bool isNarcissistic(long long n) {
	int sum = 0;

	int len = numberLength(n);

	while (n) {
		int currentD = n % 10;
		n /= 10;
		sum += pow(currentD, len);
	}

	if (sum == n) {
		return true;
	}
	
	return false;
}

//finding highest common factor of two numbers
int highestCommonFactor(int n1, int n2) {
	int min = (n1 < n2) ? n1 : n2;
	
	int HCF = 1;
	
	for (int i = 0; i <= min; i++) {
		if (n1 % i == 0 && n2 % i == 0) {
			HCF = i;
		}
	}

	return HCF;
}

//finding least common multiple of two numbers
int leastCommonMultiple(int n1, int n2) {
	int commonMultiple = 1;

	int max = (n1 > n2) ? n1 : n2;

	int i = max;

	while (1) {
		if (i % n1 == 0 && i % n2 == 0) {
			commonMultiple = i;
		}

		i += max;
	}

	return commonMultiple;
}

void encryptString() {
	char text[MAX_SIZE];
	char temp;
	int key;

	cout << "Enter the message you want to encrypt: \n";
	cin >> text;
	cout << "Enter key: \n";
	cin >> key;

	for (int i = 0; text[i] != '\0'; i++) {
		temp = text[i];
		if (temp >= 'a' && temp <= 'z') {
			temp = temp + key;

			if (temp > 'z') {
				temp = temp - 'z' + 'a' - 1;
			}

			text[i] = temp;
		}
		else if (temp >= 'A' && temp <= 'Z') {
			temp = temp + key;

			if (temp > 'Z') {
				temp = temp - 'Z' + 'A' - 1;
			}

			text[i] = temp;
		}
	}
	cout << "Encrypted message is: " << text << endl;
}
// This is an encrypted message. -> 123123...

//!!!!!!!!!!!
void multiplicationTable() {
	const char VERTICAL_LINE = '|';
	const char HORIZONTAL_LINE = '-';
	const char SPACE = ' ';

	int number;

	std::cout << "Enter your number for the multiplication table: ";
	std::cin >> number;

	int cellLength = numberLength(number * number) + 2; // 2 for the offset of the walls of the cell

	for (int i = 1; i <= 2 * number + 1; i++) {

		if (i % 2 != 0) {
			for (int j = 0; j <= cellLength * number + 1; j++) {
				std::cout << HORIZONTAL_LINE;
			}
			std::cout << std::endl;
		}
		else {
			std::cout << VERTICAL_LINE;
			for (int k = 1; k <= number; k++) {
				std::cout << SPACE << i * k / 2;

				if (2 * numberLength(i * k / 2) <= cellLength - 1) {
						for (int p = cellLength - 1; p >= numberLength(i * k / 2); p--) {
							std::cout << SPACE;
						}
					}

				std::cout << VERTICAL_LINE;						   
			}
			std::cout << std::endl;
		}
	}

}	
//!!!!!!!!!!!

/////////////////////////////////////////////////////////////////////////////////////////
//Prep Task 1
int* mergeTwoArrays(int first[], int second[], int firstLength, int secondLength) {
	int* result = new int[firstLength + secondLength];
	int index = 0;
	int i = 0; int j = 0;
	bool isFirstTraversed = false;
	bool isSecondTraversed = false;

	while (index < firstLength + secondLength) {
		if (!isFirstTraversed && !isSecondTraversed) {
			if (first[i] <= second[j]) {
				result[index] = first[i];
				i++;
			}
			else if (second[j] <= first[i]) {
				result[index] = second[j];
				j++;
			}
		}
		else if (isFirstTraversed) {
			result[index] = second[j];
			j++;
		}
		else if (isSecondTraversed) {
			result[index] = first[i];
			i++;
		}

		if (j >= secondLength) {
			isSecondTraversed = true;
		}
		if (i >= firstLength) {
			isFirstTraversed = true;
		}
		index++;
	}
	return result;
}

//Prep Task 2
struct line {
	int x1;
	int y1;
	int x2;
	int y2;
};
bool isParallelToXAxis(line firstLine, line secondLine) {
	if (firstLine.y1 == secondLine.y1 && firstLine.y2 == secondLine.y2) {
		return true;
	}

	return false;
}
bool isParallelToYAxis(line firstLine, line secondLine) {
	if (firstLine.x1 == secondLine.x1 && firstLine.x2 == secondLine.x2) {
		return true;
	}
	return false;
}
double getCommonLength(line firstLine, line secondLine) {
	if (firstLine.y1 > firstLine.y2) {
		std::swap(firstLine.y1, firstLine.y2);
	}
	if (firstLine.x1 > firstLine.x2) {
		std::swap(firstLine.x1, firstLine.x2);
	}
	if (secondLine.x1 > secondLine.x2) {
		std::swap(secondLine.x1, secondLine.x2);
	}
	if (secondLine.y1 > secondLine.y2) {
		std::swap(secondLine.y1, secondLine.y2);
	}

	if (isParallelToXAxis(firstLine, secondLine)) {
		if (firstLine.y1 <= secondLine.y1 && secondLine.y2 <= firstLine.y2) {
			return secondLine.y2 - secondLine.y1;
		}
		if (secondLine.y1 <= firstLine.y1 && firstLine.y2 <= secondLine.y2) {
			return firstLine.y2 - firstLine.y1;
		}
		if (firstLine.y2 >= secondLine.y1) {
			return firstLine.y2 - secondLine.y1;
		}
		if (secondLine.y2 >= firstLine.y1) {
			return secondLine.y2 - firstLine.y1;
		}
	}
	if (isParallelToXAxis(firstLine, secondLine))
	{
		if (firstLine.x1 <= secondLine.x1 && secondLine.x2 <= firstLine.x2)
		{
			return secondLine.x2 - secondLine.x1;
		}
		if (secondLine.x1 <= firstLine.x1 && firstLine.x2 <= secondLine.x2)
		{
			return firstLine.x2 - firstLine.x1;
		}

		if (firstLine.x2 >= secondLine.x1)
		{
			return firstLine.x2 - secondLine.x1;
		}
		if (secondLine.x2 >= firstLine.x1)
		{
			return secondLine.x2 - firstLine.x1;
		}
	}

	return -1;
}

//Prep Task 3
const int CONSOLE_WIDTH = 80;
const int CONSOLE_HEIGHT = 25;
void printRectangle(int n, int m, char symbol) {
	int x = (CONSOLE_WIDTH - n) / 2;
	int y = (CONSOLE_HEIGHT - m) / 2;

	for (int i = 0; i < x; i++) {
		cout << "\n";
	}

	for (int i = x; i < n + x; i++) {
		for (int j = 0; j < y; j++) {
			cout << " ";
		}
		for (int j = y; j < y + m; j++) {
			cout << symbol;
		}
		for (int j = y + m; j < CONSOLE_WIDTH; j++) {
			cout << " ";
		}
	}


}

//Prep Task 4
const int MAX_LENGTH = 100;
int getMatrixSum(int matrix[MAX_LENGTH][MAX_LENGTH], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j > i) {
				sum += matrix[i][j];
			}
		}
	}
	return sum;
}

//Prep Task 5
int** getTransposeMatrix(int matrix[MAX_LENGTH][MAX_LENGTH], int n) {
	int** transposedMatrix = new int* [n];
	for (int i = 0; i < n; i++) {
		transposedMatrix[i] = new int[n];
		for (int j = 0; j < n; j++) {
			transposedMatrix[i][j] = matrix[j][i];
		}
	}
	return transposedMatrix;
}

//Exam 2021/2022
//Task 1

int getLength(int number) {
	int counter = 0;
	while (number) {
		number /= 10;
		counter++;
	}
	return counter;
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int* convertNum(long number, int k, int m) {
	int lengthNumber = getLength(number);
	int* arrayOfNumber = new int[lengthNumber];

	for (int i = lengthNumber - 1; i >= 0; i--) {
		int currentD = number % 10;
		arrayOfNumber[i] = currentD;
		number /= 10;
	}

	swap(arrayOfNumber[k - 1], arrayOfNumber[m - 1]);
	return arrayOfNumber;
}

//Task 2

int getAvg(int* arr, int M) {
	int sum = 0;
	for (unsigned int i = 0; i < M; i++) {
		sum += arr[i];
	}

	return (sum / M);
}

int** splitArr(int* arr, int M) {
	const int cols = 2;
	const int numberIndex = 0;
	const int avgIndex = 1;

	int** result = new int* [M];
	int avg = getAvg(arr, M);

	for (unsigned int i = 0; i < M; i++) {
		result[i] = new int[cols];
		result[i][numberIndex] = arr[i];
		result[i][avgIndex] = avg;
	}

	return result;
}

//Task 3

bool isLower(char element) {
	return 'a' <= element && element <= 'z';
}

int getSmallLettersCount(char* str, int startIndex, int size) {
	int smallLetters = 0;
	int border = startIndex + size;
	for (unsigned i = startIndex; i < border; i++) {
		if (isLower(str[i])) {
			smallLetters++;
		}
	}

	return smallLetters;
}

bool checkBorder(char element) {
	return element != ' ' && element != '\t' && element != '\0';
}

int maxWord(char* str) {
	int maxCounter = 0;
	int startIndex = 0;
	int maxStartIndex = 0;

	for (unsigned i = 0; str[i] != '\0'; i++) {
		int counter = 0;
		if (i == 0 || str[i - 1] == ' ' || str[i - 1] == '\t') {
			startIndex = i;

			for (; checkBorder(str[i]); i++) {
				counter++;
			}

			if (counter > maxCounter) {
				maxCounter = counter;
				maxStartIndex = startIndex;
			}
		}
	}

	int smallLettersCount = getSmallLettersCount(str, maxStartIndex, maxCounter);
	int result = maxCounter * smallLettersCount;
	return result;
}

//Exam 2020/2021
//Task 1

void ConvertArr(long arr[], long S, long E) {
	if (S >= E) {
		return;
	}

	int counter = 0;
	int subArrayLength = E - S + 1;

	for (int i = S; i < (subArrayLength / 2) + S; ++i) {
		int sourceInd = i;
		int destInd = E - counter;

		int temp = arr[sourceInd];
		arr[sourceInd] = arr[destInd];
		arr[destInd] = temp;

		counter++;
	}
}

//Task 2

int findElement(long arr[], int l) {
	for (int i = l - 1; l >= 0; l--) {
		double currentAverage = (arr[i - 1] + arr[i + 1]) / 2;
		if (currentAverage < arr[i]) {
			return i;
		}
	}

	return -1;
}

//Task 3

const int MERGED_TABLE_ROWS = 2;

int** mergearrays(int* A, int* B, int m) {
	int** mergedAB = new int* [MERGED_TABLE_ROWS];
	for (unsigned i = 0; i < MERGED_TABLE_ROWS; i++) {
		mergedAB[i] = new int[m];

		for (unsigned j = 0; j < m; j++) {
			if (i == 0) {
				mergedAB[i][j] = A[j];
			}
			else if (i == 1) {
				mergedAB[i][j] = B[j];
			}
		}
	}

	return mergedAB;
}

///////Preparation 2022

//Task1
// 
//Äà ñå íàïèøå ïðîãðàìà íà C++, 
//êîÿòî çà äàäåí åäíîìåðåí ìàñèâ Arr îò äðîáíè ÷èñëà è äúëæèíà íà ìàñèâà N, 
//âðúùà íîâ ìàñèâ êîéòî ñúäúðæà ÷èñëàòà îò ïúðâèÿò, êîèòî ñà ñ íå÷åòíè èíäåêñè 
//è ñòîéíîñò ïî-ìàëêà îò ñðåäíàòà ñòîéíîñò íà Arr.

double averageSum(double arr[], int N) {
	double average = 0;
	for (int i = 0; i < N; i++) {
		average += arr[i];
	}

	average /= N;

	return average;
}

bool lessThanAverageAndOddIndex(double arr[], int index) {
	return (arr[index] < averageSum(arr, N)) && (index % 2 == 1);
}

int getSizeOfNewArray(double arr[], int N) {
	int sizeOfNewArray = 0;

	for (int i = 0; i < N; i++) {
		if (lessThanAverageAndOddIndex(arr, i)) {
			sizeOfNewArray++;
		}
	}

	return sizeOfNewArray;
}

double* programInMain(double arr[], int N) {
	int sizeOfNewArray = getSizeOfNewArray(arr, N);
	double* newArray = new double[sizeOfNewArray + 1];

	for (int i = 0; i < sizeOfNewArray; i++) {
		for (int j = 0; j < N; j++) {
			if (lessThanAverageAndOddIndex(arr, N)) {
				newArray[i] = arr[j];
			}
		}
	}

	return newArray;
}

//Task2
//Äà ñå íàïèøå ôóíêöèÿ íà C++, êîÿòî ïðèåìà êàòî ïàðàìåòúð åäíîìåðåí ìàñèâ 
//îò öåëè ÷èñëà è äúëæèíà íà ìàñèâà è âðúùà êàòî ðåçóëòàò 
//ìàêñèìàëíàòà ñóìà íà íåïðåêúñíàò ïîäìàñèâ â íåãî.
//
// Ïîÿñíåíèÿ: Íåïðåêúñíàò ïîäìàñèâ ñå íàðè÷à âñÿêà ïîñëåäîâàòåëíîñò 
//îò åëåìåíòè â äàäåí ìàñèâ, êîèòî ñà ñúñåäíè, 
//ò.å.òåõíèòå èíäåêñè ñà ïðîäúëæèòåëíè / íåïðåêúñíàòè.

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

int maxSum(int arr[], int N) {
	int maxSoFar = arr[0];
	int currMax = arr[0];
	
	for (int i = 1; i < N; i++) {
		currMax = max(arr[i], arr[i] + currMax);
		maxSoFar = max(maxSoFar, currMax);
	}

	return maxSoFar;
}

//Task3
//Äà ñå íàïèøå ïðîãðàìà íà C++, êîÿòî çà âúâåäåí îò ïîòðåáèòåëÿ îò ñòàíäàðòíèÿ 
//âõîä ñèìâîëåí íèç, íàìèðà áðîÿ íà äóìèòå ñ ÷åòíà äúëæèíà è ãî èçâåæäà íà ñòàíäàðòíèÿ èçõîä.
//
// Ïîÿñíåíèÿ: Äóìà ñå íàðè÷à âñÿêà ïîñëåäîâàòåëíîñò îò ñèìâîëè, êîÿòî 
//íå âêëþ÷âà èíòåðâàë è / èëè òàáóëàöèÿ('\t') èëè å îãðàíè÷åíà îò íà÷àëîòî è / èëè 
//êðàÿ íà íèçà.Áðîÿò íà èíòåðâàëèòå è òàáóëàöèèòå íå å îãðàíè÷åí.

const char SPACE = ' ';
const char TAB = '\t';

int wordLength(char arr[], int index) {
	int count = 0;
	while (arr[index] != ' ' || arr[index] != '\t') {
		count++;
		arr[index++];
	}
	return count;
}

int countEvenWords() {
	char* sentence;
	cout << "Enter a sentence of words: ";
	cin >> sentence;

	int countEven = 0;

	for (int i = 0; sentence[i] != '\0';) {
		if (sentence[i] != ' ' || sentence[i] != '\t') {
			if (wordLength(sentence, i) % 2 == 0) {
				countEven++;
			}
			i += wordLength(sentence, i);
		}
		else {
			i++;
		}
	}
	return countEven;
}

//Task4
//Äà ñå íàïèøå ôóíêöèÿ íà C++, êîÿòî ïðèåìà êàòî ïàðàìåòðè ñèìâîëåí íèç S è ñèìâîë C. 
// Ôóíêöèÿòà äà âðúùà êàòî ðåçóëòàò ñóìàòà íà ASCII ñòîéíîñòèòå íà äóìèòå, êîèòî çàïî÷âàò ñúñ ñèìâîëúò C.
//
// Ïîÿñíåíèÿ: Äóìà ñå íàðè÷à âñÿêà ïîñëåäîâàòåëíîñò îò ñèìâîëè, êîÿòî íå âêëþ÷âà èíòåðâàë è / èëè òàáóëàöèÿ('\t') 
// èëè å îãðàíè÷åíà îò íà÷àëîòî è / èëè êðàÿ íà íèçà.Áðîÿò íà èíòåðâàëèòå è òàáóëàöèèòå íå å îãðàíè÷åí.
// 
//ASCII ñòîéíîñò íà äóìà å ñóìàòà íà ÀSCII ñòîéíîñòèòå íà âñè÷êè ñèìâîëè îò êîèòî ñå ñúñòîè äóìàòà.

int asciiValue(char c) {
	return int(c);
}

size_t asciiSumOfC(const char S[], const char C) {
	size_t sumOfAllC = 0;
	for (int i = 0; S[i] != '\0'; i++) {
		if (S[i] == C) {
			while (S[i] != ' ' || S[i] != '\t') {
				sumOfAllC += asciiValue(S[i]);
				i++;
			}
		}
	}
	return sumOfAllC;
}

///////////////////////////////////////////////////////////////////

int main()
{
	//primes();
	//leapYears();
	//palindromes();
	//cout << factorials(50);
	/*int num;
	cout << "Enter random number to print fibonacci series:";
	cin >> num;
	cout << "Fibonacci Series for a given number: \n" << endl;
	cout << "0" << endl;
	cout << "1" << endl;
	fibonacciNumber(num - 2);*/
	//isStringPalindrome();
	//starPattern();
	//sortArray();

	/*char* result = sortLowerChars("bbzzAaaTYb");

	std::cout << result << std::endl;

	delete[] result;*/

	/*int A[N][N] = { {1, 1, 1, 1},
					{2, 2, 2, 2},
					{3, 3, 3, 3},
					{4, 4, 4, 4} };
	transposeSquareMatrix(A, N);
	
	cout << "Result matrix is \n";

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << " " << A[i][j];
		cout << "\n";
	}*/

	//multiplicationTable();

	//encryptString();



	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
