using System;
using System.Buffers;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;

public class Solution {
    public string[] solution(string[] players, string[] callings) {
      var val = players.Select((x, y) => new { name = x, idx = y}).ToDictionary(x => x.name, x => x.idx);

		foreach ( string c in callings )
		{
			int num = val[c];
			string name = players[num - 1];

			players[num - 1] = c;
			players[num] = name;

			val[c] = num - 1;
			val[name] = num;
		}
		
        return players;
    }
}