def return_sum(arr, depth):
	sum = 0
	for element in arr:
		if type(element) is int:
			sum += element
		else:
			sum += return_sum(element, depth+1)
	
	return depth*sum

def productSum(array):
    return return_sum(array, 1)