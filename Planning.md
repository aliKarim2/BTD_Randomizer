# Plan
1. Create file with tower data. For each line there will be:
   - Tower name (string)
   - Camo (bool)
   - Metal (bool)
2. Open file in code
3. Create class "Tower". Tower object will have:
   - Tower name (string)
   - Camo (bool)
   - Metal (bool)
4. Read file data into a vector of towers
5. For each player:
   - Select 3 random towers
   - Check if at least one detects camo
         - if not, refresh THIRD tower until you get one 
   - Check if at least one detects metal
           - if not, refresh SECOND tower until you get one
6. Present nicely
