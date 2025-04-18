import { Link } from "react-router-dom";
import ALink from "../components/ALink";

import schematicEditorButton from "./schematic_editor.png";

import nineNeopixels from "./9_neopixels.png";

import xiaoToNeopixel from "./xiao_to_neopixel.png";

import power from "./power.png";

import completedSchematic from "./completed_schematic.png";

import assignFootprints from "./assign_footprints.png";

import brokenXiao from "./broken_xiao.png";

import correctXiaoFootprint from "./correct_xiao_footprint.png";

import pcbEditorButton from "./pcb_editor.png";

import updatePcb from "./update_pcb.png";

import afterPcbUpdate from "./after_pcb_update.png";

import afterComponentsMoved from "./after_components_moved.png";

import decouplingCapacitors from "./decoupling_capacitors.png";

import edgeCuts from "./edge_cuts.png";

import afterEdgeCuts from "./after_edge_cuts.png";

import submissionFolder from "./submission.png";

const Guidelines = () => {
  return (
    <div className="flex flex-col items-center justify-center w-full p-4 mt-16 text-xl text-black">
      <div className="w-full max-w-4xl p-8 bg-white rounded-lg shadow-lg">
        <h1 className="mt-4 text-2xl font-bold">Allowed Parts</h1>
        <p className="mt-4">
          Please check{" "}
          <Link to="/parts" className="text-blue-500 hover:underline">
            Allowed Parts
          </Link>
        </p>

        <h1 className="mb-2 text-2xl font-bold">Requirements:</h1>
        <p className="mt-4">PCB should be 2 layered</p>
        <p className="mt-4">Max 100 cm²</p>

        <h1 className="mt-10 mb-2 text-2xl font-bold">Tutorial:</h1>
        <p className="mt-4">
          This tutorial is the bare minimum of what you need to do for the neopixels to work. Actual submissions need to have a spin of your own
          creativity ideas into it! Check out older YSWS-es like{" "}
          <a href="https://hackpad.hackclub.com/" target="_blank" rel="noopener noreferrer" className="text-blue-500 hover:underline">
            Hackpad
          </a>
          .
        </p>

        <h2 className="mb-2 text-xl font-semibold">Table of Content</h2>
        <ol className="list-decimal list-inside">
          <li>
            <a href="#resources" className="text-blue-500 hover:underline">
              Resources and tips
            </a>
          </li>

          <li>
            <a href="#getting-started" className="text-blue-500 hover:underline">
              Getting Started
            </a>
          </li>
        </ol>

        <h2 className="mt-8 mb-2 text-xl font-semibold" id="resources">
          Resources and tips
        </h2>
        <p className="mt-4">
          Hackpad have some really good resources and tips for making schematics and pcbs already so im just gonna drop it here:
          <a href="https://hackpad.hackclub.com/resources" target="_blank" rel="noopener noreferrer" className="text-blue-500 hover:underline">
            https://hackpad.hackclub.com/resources
          </a>
        </p>

        <h2 className="mt-8 mb-2 text-xl font-semibold" id="getting-started">
          Getting Started:
        </h2>
        <h3 className="text-lg font-semibold">1. You need an EDA</h3>
        <small>
          <s>tbh i am not stopping you from drawing the pcb on microsoft paint</s>
        </small>

        <p className="mt-4">I like KiCad; I use KiCad; I recommend using KiCad; we will use KiCad 🔥</p>
        <p className="mt-4">
          Download KiCad here:{" "}
          <a href="https://www.kicad.org/" target="_blank" rel="noopener noreferrer" className="text-blue-500 hover:underline">
            https://www.kicad.org/
          </a>
        </p>

        <p className="mt-4">For this project, we will use a XIAO RP2040 as our MCU</p>
        <p className="mt-4">
          Download the XIAO RP2040 footprint here:{" "}
          <a
            href="https://github.com/Seeed-Studio/OPL_Kicad_Library/"
            target="_blank"
            rel="noopener noreferrer"
            className="text-blue-500 hover:underline">
            https://github.com/Seeed-Studio/OPL_Kicad_Library/
          </a>
        </p>

        <p className="mt-4">There are many tutorials on how to install libraries! A wise man once said:</p>
        <blockquote className="pl-4 italic border-l-4 border-blue-500">
          <a
            href="https://hackpad.hackclub.com/guide#:~:text=Google is your best friend here :)"
            target="_blank"
            rel="noopener noreferrer"
            className="text-blue-500 hover:underline">
            Google is your best friend here :)
          </a>
        </blockquote>

        <h3 className="mt-8 text-lg font-semibold">2. Draw the schematic</h3>
        <small>This is the easy part, just connect the dots. /s</small>

        <p className="mt-4">After creating a project in KiCad, click on the "Schematic Editor" button:</p>
        <img src={schematicEditorButton} alt="Schematic Editor Button" />

        <p className="mt-4">
          Once you're in, press the <code>A</code> key on your keyboard. This should open up a menu where you can add symbols for your different
          components! Search for the following to add them:
        </p>
        <ul className="list-disc list-inside">
          <li>XIAO-RP2040-DIP (your microcontroller)</li>
          <li>
            A neopixel choice from{" "}
            <Link to="/parts#neopixels" className="text-blue-500 hover:underline">
              Allowed Parts
            </Link>
          </li>
          <li>
            <code>C</code> for capacitors, we will use them as decoupling capacitors to prevent voltage drop brownouts.
          </li>
        </ul>

        <p className="mt-4">
          To start, add 9 neopixels. To rotate the symbols, click R. And to mirror them, click X. Connect the neopixels in series with their DIN and
          DOUT pins:
        </p>
        <img src={nineNeopixels} alt="9 Neopixels" />

        <p className="mt-4">Connect the first neopixel DIN to a GPIO pin on the XIAO:</p>
        <img src={xiaoToNeopixel} alt="XIAO to Neopixel" />

        <p className="mt-4">Don't forget their power! Press P and search for +5V and GND. It should look like this:</p>
        <img src={power} alt="Power" />

        <p className="mt-4" id="decoupling-capacitors">
          Decoupling capacitors help with voltage drops! You should have 1 or more big capacitor at the start of the power rail, and multiple small
          ones for every couple pixels. For 9 neopixels, I used 1 100uF capacitor and small 4.7nF ones for each row.
        </p>
        <img src={decouplingCapacitors} alt="Decoupling Capacitors" />

        <p className="mt-4">
          Just remember to put the capacitors near what they are for on the PCB! Please read online for more information about decoupling
          capacitors!!!
        </p>

        <p className="mt-4">
          That's the absolute requirements for Pixeldust. For an approvable submission, please add some of your creativity ideas into it like a
          button, a knob, a photodetector.
        </p>

        <p className="mt-4">My completed schematic:</p>
        <img src={completedSchematic} alt="Completed Schematic with leds, xiao, and buttons" />
        <p className="mt-4">Remember to assign footprints to your components!</p>
        <img src={assignFootprints} alt="Assign Footprints" />

        <p className="m-10 border-l-4 border-red-500 pl-4 bg-red-100">
          <strong>NOTE:</strong> There is a bug in the Seeed XIAO Library, the footprint assigned to the symbol is not correct and it won't resolve
          when you update your PCB from the schematic! Please reassign the symbol with the correct footprint!!!!
        </p>

        <img src={brokenXiao} alt="Broken Xiao symbol footprint link" />

        <img src={correctXiaoFootprint} alt="Correct Xiao Footprint" />

        <h3 className="mt-8 text-lg font-semibold">3. Draw the PCB</h3>
        <small>best artist in town /s</small>

        <p className="mt-4">After you have completed your schematic, click on the "PCB Editor" button:</p>
        <img src={pcbEditorButton} alt="PCB Editor Button" />

        <p className="mt-4">This will bring you to the PCB editor. Start by populating your board with components from the schematic.</p>
        <img src={updatePcb} alt="Update PCB" />

        <p className="mt-4">After updating the PCB, it should look like below. I chose the Cherry MX switches for the switches footprint.</p>
        <small>surely i wont bankrupt mohid with the switches :clueless:</small>
        <img src={afterPcbUpdate} alt="After Update PCB" />

        <p className="mt-4">
          Move your components around however you like it. Have your decoupling capacitors close to what they are for. The big value one should be
          closer to the power source (the XIAO in this case), and the smaller ones can be closer to the neopixels
        </p>
        <img src={afterComponentsMoved} alt="After Components Moved" />

        <p className="mt-4">
          Don't forget to add the edge cuts! This is the outline of your PCB. It should be a closed loop and not intersect with anything else.
          <br />
          To add edge cuts, click on the "Edge.Cuts" layer on the right side of the screen. Then click on the "Draw Rectangle" button. Draw a
          rectangle around your PCB. It should look like this:
        </p>
        <img className="m-8" src={edgeCuts} alt="Edge Cuts" />
        <img src={afterEdgeCuts} alt="After Edge Cuts" />

        <small>
          i gtg to my english class, you can get more directions here, pcb routing is very general so most stuff from hackpad applies here as well:{" "}
          <ALink href="https://hackpad.hackclub.com/guide#:~:text=There%20is%20a%20front%20side%20and%20back%20side%20of%20the%20board.%20You%20can%20tell%20them%20apart%20by%20color">
            hackpad guide
          </ALink>
        </small>

        <h2 className="mt-8 mb-2 text-xl font-semibold">SUBMISSIONS:</h2>
        <p className="mt-4">
          Fork the GitHub repo:{" "}
          <a href="https://github.com/hackclub/pixeldust" className="text-blue-500 hover:underline">
            m0hid/pixeldust
          </a>
        </p>

        <p className="mt-4">
          Press <code>.</code> on your keyboard to open online VS Code
        </p>

        <p className="mt-4">
          In the submission folder, create a new folder with your board name. Copy README.md from the <code>!Template</code> folder and fill in your
          info. Please add lots of pictures of your board!! e.g. renders of your PCB, the schematic and the pcb design itself,... If you have any
          questions with the info in the README.md, don't hesitate to ask on #pixeldust on Slack!
        </p>

        <p className="mt-4">
          Generate a PDF of your schematic and a BOM and add it in your submission folder! If your schematic is larger than the sheet, please split it
          into multiple sheets and adjust your sheet size to fit all of the components. Otherwise, the PDF will clip the components outside of the
          sheet.
        </p>

        <p className="mt-4">
          In your submission folder, create a new folder called <code>src</code>. This is where you will put your KiCad or any EDA files. Please
          delete the backup files before uploading!
        </p>

        <p className="mt-4">
          Create another folder called <code>production</code>. This is where you will put your Gerber files. If you have a different version from
          your Wokwi project, put your firmware source code here too. If you want PCBA, please put your CPL file in the <code>production</code> folder
          as well.
        </p>

        <p className="mt-4">It should look like this:</p>
        <img src={submissionFolder} alt="Submission Folder" />

        <p className="mt-4">Commit your changes and push them to your forked repo. After that you can create your Pull Request!</p>

        <p className="mt-4">
          <strong>NOTE:</strong> Please make sure to check your pull request for any errors before submitting. If you have any questions, feel free to
          ask in the #pixeldust channel.
        </p>
      </div>
    </div>
  );
};

export default Guidelines;
