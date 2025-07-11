class Solution:
	def isPlaindrome(self, S):
		# code here
		l = len(S)
		flag = 0
		for i in range(l):
		    if S[i]!=S[l-i-1]:
		        flag=1
		        break
		if flag==0:
		    return 1
		else:
		    return 0

if __name__ == "__main__":
    text = "saiabhiteja"
    ob = Solution()
    x = ob.isPlaindrome(text)
    if x ==1:
        print("palindrome")
    else:
        print("Not a palindrome")