def linear_search(array, value)
  # we interate throu every element in the array:
  array.each do |element|
    #if we find the value we're looking for, we return it:
    if element == value
      return value
    # If we reach an element that is greater than the value 
    # we're looking for, we can exit the loop early:
    elsif element > value
      break
    end
  end
  # We return nil if we do not find the value within the array:
  return nil
end
# my question 
#1. what is nil
#2. if element empty
#3. If it's has 2 value in array
