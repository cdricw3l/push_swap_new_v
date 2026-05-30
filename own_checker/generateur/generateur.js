
    const process = require('node:process');
    const fs = require('node:fs');
    // ── State ──
    let genNums = '';   // full space-separated string — ALWAYS full, never truncated
    
    // ── Inversion count O(n log n) ──
    function countInversions(arr) {
      let c = 0;
      function mg(a) {
        if (a.length <= 1) return a;
        const m = a.length >> 1, L = mg(a.slice(0, m)), R = mg(a.slice(m)), o = [];
        let i = 0, j = 0;
        while (i < L.length && j < R.length) {
          if (L[i] <= R[j]) o.push(L[i++]);
          else { o.push(R[j++]); c += L.length - i; }
        }
        while (i < L.length) o.push(L[i++]);
        while (j < R.length) o.push(R[j++]);
        return o;
      }
      mg(arr.slice()); return c;
    }

    // ── Disorder generation (adjacent-swap, exact) ──
    function genDisorder(size, ratio) {
      const arr = Array.from({ length: size }, (_, i) => i + 1);
      const tp = (size * (size - 1)) / 2;
      const ti = Math.floor(ratio * tp);
      if (ti <= 0) return arr;
      if (ti >= tp) return arr.slice().reverse();
      let ci = 0, att = 0, max = ti * 6 + size * 4;
      while (ci < ti && att < max) {
        const i = Math.floor(Math.random() * (size - 1));
        if (arr[i] < arr[i + 1]) { [arr[i], arr[i + 1]] = [arr[i + 1], arr[i]]; ci++; }
        att++;
      }
      for (let i = 0; i < size - 1 && ci < ti; i++)
        if (arr[i] < arr[i + 1]) { [arr[i], arr[i + 1]] = [arr[i + 1], arr[i]]; ci++; }
      return arr;
    }

    // ── Pick `count` random unique integers from [min, max] ──
    function pickRandom(min, max, count) {
      const rangeSize = max - min + 1;
      if (count >= rangeSize) {
        // use all values
        return Array.from({ length: rangeSize }, (_, i) => min + i);
      }
      // Fisher-Yates partial shuffle on the range
      const pool = Array.from({ length: rangeSize }, (_, i) => min + i);
      for (let i = 0; i < count; i++) {
        const j = i + Math.floor(Math.random() * (rangeSize - i));
        [pool[i], pool[j]] = [pool[j], pool[i]];
      }
      return pool.slice(0, count);
    }

   
    function multi_generation()
    {
      let min = -500;
      let max = 500;
      let r_start = 2;
      let r_end = 500;
      let ratio = 0.3;

      while(r_start <= r_end)
      {
        let list = generate(min, max, r_start, ratio).concat("\n");
        fs.writeFile("test_liste.txt", list,{flag:'a'}, err => {
          if (err) 
          {
            console.log("Error")
            return;
          }
        })
        r_start++;
      }
    }
    
    
    // ── Generate ──
    function generate(mn, mx, cnt, ratio) {

      // 1. Pick `cnt` unique values from [mn, mx]
      const picked = pickRandom(mn, mx, cnt);
      // 2. Sort them to get rank order
      const sorted = picked.slice().sort((a, b) => a - b);
      // 3. Generate disorder permutation of indices 0..cnt-1
      const perm = genDisorder(cnt, ratio);
      // 4. Map permutation indices to actual picked values
      // perm[i] is rank (1-based), so the value at position i = sorted[perm[i]-1]
      const result = perm.map(rank => sorted[rank - 1]);

      // 5. Compute actual disorder
      const tp = (cnt * (cnt - 1)) / 2;
      const actualInv = countInversions(perm);
      const actualDis = tp > 0 ? (actualInv / tp) : 0;

      // FULL sequence — no truncation
      genNums = result.join(' ');
      return(genNums)
    }

    multi_generation()