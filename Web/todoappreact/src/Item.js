import { IconButton } from "@material-ui/core";
import { CancelOutlined } from "@material-ui/icons";
import React from "react";
import { db } from "./firebase";
import "./Item.css";

function Item({ task, deleteItem, id, isChecked }) {
	function check(e) {
		e.preventDefault();
		db.collection("tasks").doc(id).update({ isChecked: !isChecked });
	}

	return (
		<div
			className={isChecked ? "item checked" : "item"}
			onClick={(e) => check(e)}>
			<div className='item__name'>
				<p>{task}</p>
			</div>
			<IconButton title='Remove Task' onClick={() => deleteItem(id)}>
				<CancelOutlined />
			</IconButton>
		</div>
	);
}

export default Item;
