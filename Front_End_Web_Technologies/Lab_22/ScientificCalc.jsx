import { useState } from "react";
import "./SimpleCalc.css";

function ScientificCalc() {
  const [exp, setExp] = useState("");
  const [ans, setAns] = useState("");

  const functionalities = (values) => {
    if (values == "ac") {
      setExp("");
      setAns("");
    } else if (values == "x") {
      setExp(exp.slice(0, -1));
    } else if (values == "=") {
      try {
        let expression =
          exp
            .replace(/sin/g, "Math.sin")
            .replace(/cos/g, "Math.cos")
            .replace(/tan/g, "Math.tan")
            .replace(/log/g, "Math.log")
            .replace(/sqrt/g, "Math.sqrt")
            .replace(/exp/g, "Math.exp")
            .replace(/pow/g, "Math.pow")
            .replace(/pi/g, "Math.PI")
        ;
        setAns(String(eval(expression)));
      } catch {
        setAns("Syntax Error");
      }
    } else {
      setExp(exp + values);
    }
  };

  return (
    <table border={1} cellSpacing={0}>
      <tbody>
        <tr>
          <td colspan="4">
            <input type="text" style={{ height: "25px" }} value={exp} />
            <br />
            <input
              type="text"
              id="mytext"
              disabled
              style={{ height: "25px" }}
              value={ans}
            />
          </td>
        </tr>

        <tr>
          <td>
            <button onClick={() => functionalities("sin")}>sin</button>
          </td>
          <td>
            <button onClick={() => functionalities("cos")}>cos</button>
          </td>
          <td>
            <button onClick={() => functionalities("tan")}>tan</button>
          </td>
          <td>
            <button onClick={() => functionalities("log")}>log</button>
          </td>
        </tr>
        <tr>
          <td>
            <button onClick={() => functionalities("sqrt")}>sqrt</button>
          </td>
          <td>
            <button onClick={() => functionalities("exp")}>exp</button>
          </td>
          <td>
            <button onClick={() => functionalities("pow")}>pow</button>
          </td>
          <td>
            <button onClick={() => functionalities("pi")}>pi</button>
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

export default ScientificCalc;
