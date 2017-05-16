/*
 * https://www.codechef.com/MAY17/problems/CHEFCODE
 */

package main

import (
	"bufio"
	"fmt"
	"math/big"
	"os"
	"sort"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)
var wtr = bufio.NewWriter(os.Stdout)

/* ByBigInt implements sort.Interface for []*(big.Int) */
type ByBigInt []*(big.Int)

func (a ByBigInt) Len() int           { return len(a) }
func (a ByBigInt) Less(i, j int) bool { return a[i].Cmp(a[j]) == -1 }
func (a ByBigInt) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }

func meetInTheMiddle(v []uint64) []*(big.Int) {
	power := 1 << uint(len(v))
	result := make([]*big.Int, 0, power)

	for i := 0; i < power; i++ {
		var product = big.NewInt(1)
		for j := 0; j < len(v); j++ {
			if ((i >> uint(j)) & 1) == 1 {
				product = new(big.Int).Mul(product, big.NewInt(int64(v[j])))
			}
		}
		result = append(result, product)
	}

	// > Go 1.4
	// sort.Slice(result, func(i int, j int) bool {
	// 	return result[i].Cmp(result[j]) == -1
	// })
	sort.Sort(ByBigInt(result))

	return result

}
func exec() {
	var n int
	var k uint64
	fmt.Scanf("%d", &n)
	fmt.Scanf("%d", &k)
	a := make([]uint64, n)

	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
	}

	if n == 1 {
		if a[0] <= k {
			fmt.Fprintln(wtr, 1)
		} else {
			fmt.Fprintln(wtr, 0)
		}
		_ = wtr.Flush()
		return
	}
	var firstHalfProducts = meetInTheMiddle(a[0 : len(a)/2])
	var lastHalfProducts = meetInTheMiddle(a[len(a)/2:])
	// for i := 0; i < len(firstHalfProducts); i++ {
	// 	fmt.Printf("first[%d] = %s\n", i, firstHalfProducts[i].String())
	// }
	// for i := 0; i < len(lastHalfProducts); i++ {
	// 	fmt.Printf("last[%d] = %s\n", i, lastHalfProducts[i].String())
	// }

	ans := big.NewInt(0)
	bigK := big.NewInt(int64(k))

	for i := 0; i < len(firstHalfProducts); i++ {
		threshold := new(big.Int).Div(bigK, firstHalfProducts[i])
		index := sort.Search(len(lastHalfProducts), func(j int) bool { return lastHalfProducts[j].Cmp(threshold) == 1 })
		// fmt.Printf("first[%d] = %s, threshold = %s, index = %d\n", i, firstHalfProducts[i].String(), threshold.String(), index)
		ans.Add(ans, big.NewInt(int64(index)))

	}
	// fmt.Printf("ans = %s\n", ans.String())
	fmt.Fprintln(wtr, ans.Sub(ans, big.NewInt(1)))
	_ = wtr.Flush()

}

func nextInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}

func main() {
	exec()
}
