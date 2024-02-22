from typing import List, Tuple, Optional, Any
from pathlib import Path

from outflank_stage1.task.base_bof_task import BaseBOFTask
from outflank_stage1.task.enums import BOFArgumentEncoding
from outflank_stage1.task.exceptions import TaskInvalidArgumentsException


class testBOF(BaseBOFTask):
    def __init__(self):
        super().__init__("bof-test",
                         base_binary_path="bin",
                         base_binary_name="test"
        )

        self.parser.add_argument(
            "pid",
            type=int,
            help="pid."
        )

        self.parser.description = "test bof"

    def split_arguments(self, arguments: Optional[str]) -> List[str]:
        return super().split_arguments(arguments, True)

    def _encode_arguments_bof(self, arguments: List[str]) -> List[Tuple[BOFArgumentEncoding, Any]]:
        parser_arguments = self.parser.parse_args(arguments)

        return [
            (BOFArgumentEncoding.INT, parser_arguments.pid),
        ]
