import React from "react";
import {Button , withStyles, Typography, IconButton } from "@material-ui/core";
import MenuIcon from '@material-ui/icons/Menu'
import socketIOClient from "socket.io-client";
import PropTypes from 'prop-types';

const useStyles = {
    adas: {
        backgroundColor: "#b2ff59",
        color: "black",
        // maxHeight: "50px",
        height: "30px",
    },
    circleStyle: {
        padding:10,
        margin:20,
        display:"inline-block",
        borderRadius: "50%",
        backgroundColor: "black",
        width:100,
        height:100,
    }
};

function Traffic(props){
    const {classes} = props;
    return(
        <div>
        <div className={classes.circleStyle}> </div>
        <div className={classes.circleStyle}> </div>
        <div className={classes.circleStyle}> </div>
        </div>
    );
}

Traffic.propTypes = {
    classes: PropTypes.object.isRequired,
} ;

export default withStyles(useStyles)(Traffic);
