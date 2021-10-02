import { useState } from "react";
import ReactMarkdown from "react-markdown";
import "./index.css";

export default function App() {
  const [markDown, setMarkDown] = useState("Welcome to MarkDown !");
  const heading = {
    textAlign: "center"
  };
  return (
    <>
      <h1 style={heading}> Welcome to MarkDown Code Editor </h1>
      <div className="center-div">
        <textarea
          className="left-side"
          value={markDown}
          onChange={(e) => {
            setMarkDown(e.target.value);
          }}
        ></textarea>
        <div className="right-side">
          <ReactMarkdown>{markDown}</ReactMarkdown>
        </div>
      </div>
    </>
  );
}
