package calc;

/**
 * @author a13596
 * 有理数クラス
 * 分子と分母を持ち、算術演算を行える
 *
 */
public class Fraction {
	
	private long numerator;		// 分子
	private long denominator;	// 分母
	
	public Fraction(long num, long den){
		if(den == 0) throw new IllegalArgumentException("分母が0です。");
		this.numerator = num;
		this.denominator = den;
	}
	
	public Fraction(long num){
		this(num, 1);
	}
	
	public Fraction(){
		this(0, 1);
	}
	
	/** 算術演算*/
	public Fraction add(Fraction f){
		long den = lcm(denominator, f.denominator);
		long num = numerator * (den / denominator) 
				+ f.numerator * (den / f.denominator);
		long g = gcd(den, num);
		return new Fraction(num / g, den / g);
	}
	
	public Fraction subtract(Fraction f){
		long den = lcm(denominator, f.denominator);
		long num = numerator * (den / denominator) 
				- f.numerator * (den / f.denominator);
		long g = gcd(den, num);
		return new Fraction(num / g, den / g);
	}
	
	public Fraction multiply(Fraction f){
		long den = denominator * f.denominator;
		long num = numerator * f.numerator;
		long g = gcd(den, num);
		return new Fraction(num / g, den / g);
	}
	
	public Fraction divide(Fraction f){
		long den = denominator * f.numerator;
		long num = numerator * f.denominator;
		long g = gcd(den, num);
		return new Fraction(num / g, den / g);
	}
	
	public long getNumerator(){
		return numerator;
	}
	
	public long getDenominator(){
		return denominator;
	}
	
	/** a, bの最大公約数を求める*/
	public static long gcd(long a, long b){
		return _gcd(Math.max(a, b), Math.min(a, b));
	}
	
	private static long _gcd(long a, long b){
		return b == 0 ? a : _gcd(b, a % b);
	}
	
	/** a, bの最小公倍数を求める */
	public static long lcm(long a, long b){
		return a * b / gcd(a, b);
	}
	
	@Override
	public String toString(){
		if(denominator == 1){
			return String.valueOf(numerator);
		} else{
			return String.format("%d/%d", numerator, denominator);
		}
	}
	
	/** 
	 * @param isDouble trueなら戻り値を少数表記、falseなら分数表記にする
	 * @return 数式の文字列
	 *  */
	public String toString(boolean isDouble){
		if(isDouble){
			return String.valueOf((double)numerator / denominator);
		} else{
			return toString();
		}
	}

}
