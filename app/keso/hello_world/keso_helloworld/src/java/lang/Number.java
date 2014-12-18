// @formatter:off
/**(c)

  Copyright (C) 2006-2013 Christian Wawersich, Michael Stilkerich,
                          Christoph Erhardt

  This file is part of the KESO Java Runtime Environment.

  KESO is free software: you can redistribute it and/or modify it under the
  terms of the Lesser GNU General Public License as published by the Free
  Software Foundation, either version 3 of the License, or (at your option)
  any later version.

  KESO is distributed in the hope that it will be useful, but WITHOUT ANY
  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
  FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
  more details. You should have received a copy of the GNU Lesser General
  Public License along with KESO. If not, see <http://www.gnu.org/licenses/>.

  Please contact keso@cs.fau.de for more info.

  (c)**/
// @formatter:on

package java.lang;

//import java.io.Serializable;

//public abstract class Number implements Serializable {
public abstract class Number {
    public Number() {}

    public abstract int intValue();
    //public int intValue() { throw new Error(""); }

    public abstract long longValue();
  /*
    public abstract float floatValue();
    public abstract double doubleValue();
    */

    public byte byteValue() {
	return (byte) intValue();
    }

    public short shortValue() {
	return (short) intValue();
    }
}
