# First, we establish the lower and upper bounds of where the value
# we're searching for can be. To start, the lower bound is the first
# value in the array, while the upper bound is the last value"
def binary_search(array, value)
    lower_bound = 0
    upper_bound = array.length -1 
    # we begin a loop in which we keep inspecting the middlemost value
  # between thhe upper and lower bounds:
  while lower_bound <= upper_bound do
    # we find the midpoint between the upper and lower bounds:
    #(we dont't have to worry about the result being a non-integer 
    # since in ruby , the result of division of integers will always
    # be rounded down to the nearest integer.)
    mid point = ( upper_bound + lower_bound) / 2 
    # we inspect the value at the midpoint:
    value_at_midpoint = array[midpoint]
    #if the value at the mid point is the one we're looking for, we're done 
    # if not, we change the lower or upper bound based on wether we need
    # to guess higher or lower:
    if value < value_at_midpoint 
      upper_bound = midpoint - 1
    elsif value > value_at_midpoint
      lower_bound = midpoint + 1
    elsif value == value_at_midpoint
      return midpoint
    end
  end
  # if we've narrowed the bound until they've reached each other that
  # means that the value we're searching for is not contained witht 
  # this array"
  return nil
end
    
