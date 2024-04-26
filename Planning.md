# Plan
1. Create file with tower data. For each line there will be:
   - Tower name (string)
   - Pops all (bool)
   - hype (bool)
2. Open file in code
3. Create class "Tower". Tower object will have:
   - Tower name (string)
   - Pops all (bool)
   - Hype (bool)
4. Read file data into a vector of towers
5. For each player:
   - Do the algorithm listed at bottom
6. Present nicely

# Checklist
- [ ] Step 1
- [ ] Step 2
- [x] Step 3
- [ ] Step 4
- [ ] Step 5
- [x] Step 6

## Tower Sorting Algorithm
1. Check if map has water in it or not
2. If map has NO water, whenever generating, do so from 2 to tower count instead of 0 to tower count (first two towers in file are the water ones)
3. Else, stick with generating from 0 to tower count
4. first element will be a tower that pops all (select index from popsAllList)
5. second element will be hype (select index from hypeList)
6. third will be any tower (select index from towerList)
7. Make sure there are no duplicates
