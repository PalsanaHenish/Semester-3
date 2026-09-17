import { useState } from "react";
import "./SimpleCalc.css";

function SimpleCalc() {
  const [exp, setExp] = useState("");
  const [ans, setAns] = useState("");

  const functionalities = (values) => {
    if (values == "ac") {
      setExp("");
      setAns('');
    } else if (values == "x") {
      setExp(exp.slice(0, -1));
    } else if (values == "=") {
      try {
        setAns(String(eval(exp)));
      } catch {
        setAns("Syntax Error");
      }
    } else {
      setExp(exp + values);
    }
  };

  return (
    <table border={1} celspacing={0}>
      <tbody>
        <tr>
          <td colspan="4">
            <input type="text" style={{ height: "25px;" }} value={exp} />
            <br />
            <input
              type="text"
              id="mytext"
              disabled
              style={{ height: "25px;" }}
              value={ans}
            />
          </td>
        </tr>

        <tr>
          <td>
            <button onClick={() => functionalities("ac")}>AC</button>
          </td>
          <td>
            <button onClick={() => functionalities("x")}>Del</button>
          </td>
          <td>
            <button onClick={() => functionalities("%")}>%</button>
          </td>
          <td>
            <button onClick={() => functionalities("/")}>/</button>
          </td>
        </tr>
        <tr>
          <td>
            <button onClick={() => functionalities("1")}>1</button>
          </td>
          <td>
            <button onClick={() => functionalities("2")}>2</button>
          </td>
          <td>
            <button onClick={() => functionalities("3")}>3</button>
          </td>
          <td>
            <button onClick={() => functionalities("*")}>*</button>
          </td>
        </tr>
        <tr>
          <td>
            <button onClick={() => functionalities("4")}>4</button>
          </td>
          <td>
            <button onClick={() => functionalities("5")}>5</button>
          </td>
          <td>
            <button onClick={() => functionalities("6")}>6</button>
          </td>
          <td>
            <button onClick={() => functionalities("+")}>+</button>
          </td>
        </tr>
        <tr>
          <td>
            <button onClick={() => functionalities("7")}>7</button>
          </td>
          <td>
            <button onClick={() => functionalities("8")}>8</button>
          </td>
          <td>
            <button onClick={() => functionalities("9")}>9</button>
          </td>
          <td>
            <button onClick={() => functionalities("-")}>-</button>
          </td>
        </tr>
        <tr>
          <td>
            <button onClick={() => functionalities("0")}>0</button>
          </td>
          <td>
            <button onClick={() => functionalities("00")}>00</button>
          </td>
          <td>
            <button onClick={() => functionalities(".")}>.</button>
          </td>
          <td>
            <button onClick={() => functionalities("=")}>=</button>
          </td>
        </tr>
      </tbody>
    </table>
  );
}

export default SimpleCalc;
