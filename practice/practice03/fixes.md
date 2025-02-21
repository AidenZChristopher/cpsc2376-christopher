Bug Fixes

BUG: for (int i = start; i < end; i++)
Why: The loop doesn't include the end which stops it one value early
Fix: for (int i = start; i <= end; i++)

BUG: for (size_t i = 0; i <= numbers.size(); i++)
Why: i = numbers.size() makes the indice out of range
Fix: for (size_t i = 0; i < numbers.size(); i++) 

BUG: if (numbers[i] > 0)
Why: Functions checks for positive nums instead of neg numbers
Fix: if (numbers[i] < 0)
 
BUG: if (numbers.empty()) return 0;
Why: returning 0 is bad practice since 0 can be a valid num in int
Fix: if (numbers.empty()) return false;

BUG: for (size_t i = 1; i <= numbers.size(); i++)
Why: i = numbers.size gives an invalid range
Fix: for (size_t i = 1; i < numbers.size(); i++)

BUG: if (numbers[i] >= maxVal)
Why: i == numbers.size is out of range
Fix: if (numbers[i] >= maxVal)
